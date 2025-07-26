#include "OutlineCollapser.h"
#include "OutlineCollapserSettings.h"
#include "OutlineCollapserCommands.h"

#include "LevelEditor.h"
#include "Selection.h" 
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FOutlineCollapserModule"

void FOutlineCollapserModule::StartupModule()
{
    RegisterSettings();
    RebindCommands();
    
    // Register editor actor selected
    GEditor->GetSelectedActors()->SelectObjectEvent.AddRaw(this, &FOutlineCollapserModule::OnActorSelected);
    
    // Register editor actor dropped to level
    //GEditor->OnLevelActorAdded().AddRaw(this, &FOutlineCollapserModule::OnActorAdded);
    FEditorDelegates::OnNewActorsDropped.AddRaw(this, &FOutlineCollapserModule::OnActorsDropped);

    // Register editor level events
    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
    LevelEditorModule.OnTabManagerChanged().AddRaw(this, &FOutlineCollapserModule::OnTabManagerChanged);

    // Add custom sections to UE Menu Builder
    TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());

    /*
    // Estendi il menu "Window"
    MenuExtender->AddMenuExtension(
        "WindowLayout",
        EExtensionHook::After,
        PluginCommands,
        FMenuExtensionDelegate::CreateRaw(this, &FOutlineCollapserModule::AddEntriesToMenu));

    // Estendi il menu "Actors"
    MenuExtender->AddMenuExtension(
        "ActorControl", // Puoi usare anche "Edit" o "Transform" per altre posizioni
        EExtensionHook::After,
        PluginCommands,
        FMenuExtensionDelegate::CreateRaw(this, &FOutlineCollapserModule::AddEntriesToMenu));

    // Registra il menu extender per gli attori selezionati
    LevelEditorModule.GetAllLevelEditorContextMenuExtenders().Add(
        FLevelEditorModule::FLevelEditorMenuExtender::CreateLambda(
            [MenuExtender](const TSharedRef<FUICommandList>&, const TArray<AActor*>&)
            {
                return MenuExtender.ToSharedRef();
            })
    // Update Menus with our Extensions
    LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
    */

    // Add our command action
    LevelEditorModule.GetGlobalLevelEditorActions()->Append(PluginCommands.ToSharedRef());

    // Add a watcher to drag&dropped actors
    FinalizationWatcher = MakeShared<FActorFinalizationWatcher>();
    FinalizationWatcher->OnAllPendingActorsFinalized.AddRaw(this, &FOutlineCollapserModule::OnDroppedActorsFinalized);

}

void FOutlineCollapserModule::ShutdownModule()
{
    FOutlineCollapserCommands::Unregister();

    FEditorDelegates::OnNewActorsDropped.RemoveAll(this);

    GEditor->GetSelectedActors()->SelectObjectEvent.RemoveAll(this);

    if (FModuleManager::Get().IsModuleLoaded("LevelEditor"))
    {
        FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>("LevelEditor");
        LevelEditorModule.OnTabManagerChanged().RemoveAll(this);
    }

    FinalizationWatcher->OnAllPendingActorsFinalized.RemoveAll(this);

}

void FOutlineCollapserModule::RegisterSettings()
{
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->RegisterSettings(
            "Editor", "Plugins", "OutlineCollapser",
            LOCTEXT("OutlineCollapserSettingsName", "Outline Collapser"),
            LOCTEXT("OutlineCollapserSettingsDescription", "Configure Outliner collapse behavior and hotkey."),
            GetMutableDefault<UOutlineCollapserSettings>()
        );
    }

    // Notify when a setting change
    if (auto* Settings = GetMutableDefault<UOutlineCollapserSettings>())
    {
        Settings->OnKeybindChanged().AddRaw(this, &FOutlineCollapserModule::OnKeybindChanged);
    }
}

void FOutlineCollapserModule::OnKeybindChanged()
{
    RebindCommands();
}

void FOutlineCollapserModule::RebindCommands()
{
    if (!PluginCommands)
    {
        PluginCommands = MakeShareable(new FUICommandList);
    }

    // De-Register
    if (FOutlineCollapserCommands::IsRegistered())
    {
        auto Action = FOutlineCollapserCommands::Get().ExpandParentsOfSelectedItems;
        if (PluginCommands->IsActionMapped(Action))
        {
            PluginCommands->UnmapAction(Action);
            FOutlineCollapserCommands::Unregister();
        }
    }

    // Re-Register
    FOutlineCollapserCommands::Register();
    auto Action = FOutlineCollapserCommands::Get().ExpandParentsOfSelectedItems;
    PluginCommands->MapAction(
        Action,
        FExecuteAction::CreateRaw(this, &FOutlineCollapserModule::ExpandParentsOfSelectedItems),
        FCanExecuteAction()
    );
}

void FOutlineCollapserModule::AddEntriesToMenu(FMenuBuilder& MenuBuilder)
{
    MenuBuilder.AddMenuEntry(FOutlineCollapserCommands::Get().ExpandParentsOfSelectedItems);
}

bool FOutlineCollapserModule::GetFirstSceneOutliner(TSharedPtr<SSceneOutliner>& SceneOutliner)
{
    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
    TSharedPtr<FTabManager> TabManager = LevelEditorModule.GetLevelEditorTabManager();
    if (!TabManager.IsValid()) 
        return false;

    TSharedPtr<SDockTab> OutlinerTab = TabManager->FindExistingLiveTab(FTabId(FName("LevelEditorSceneOutliner")));
    if (!OutlinerTab.IsValid())
        return false;

    TSharedRef<SWidget> TabContent = OutlinerTab->GetContent();

    // Ricerca ricorsiva per trovare il primo SSceneOutliner
    TFunction<void(const TSharedRef<SWidget>&)> SearchWidget;
    SearchWidget = [&SceneOutliner, &SearchWidget](const TSharedRef<SWidget>& Widget)
        {
            if (Widget->GetTypeAsString() == "SSceneOutliner")
            {
                SceneOutliner = StaticCastSharedRef<SSceneOutliner>(Widget);
                return;
            }

            FChildren* Children = Widget->GetChildren();
            for (int32 i = 0; i < Children->Num(); ++i)
            {
                SearchWidget(Children->GetChildAt(i));
                if (SceneOutliner.IsValid())
                {
                    return;
                }
            }
        };
    SearchWidget(TabContent);

    //SceneOutliner = FoundOutliner;
    return SceneOutliner.IsValid();
}

void FOutlineCollapserModule::OnTabManagerChanged()
{
    UOutlineCollapserSettings* Settings = GetMutableDefault<UOutlineCollapserSettings>();
    if (Settings && Settings->bCollapseOnStartup)
    {
        CollapseVisibleSceneOutlinerOnNextTick();   
    }
}

void FOutlineCollapserModule::OnActorsDropped(const TArray<UObject*>& Objects, const TArray<AActor*>& Actors)
{
    const UOutlineCollapserSettings* Settings = GetDefault<UOutlineCollapserSettings>();
    if (Settings && Settings->bCollapseOnActorDropped)
    {
        FinalizationWatcher->AddActors(Actors);
    }
}

void FOutlineCollapserModule::OnDroppedActorsFinalized()
{
    const UOutlineCollapserSettings* Settings = GetDefault<UOutlineCollapserSettings>();
    if (Settings && Settings->bCollapseOnActorDropped)
    {
        CollapseVisibleSceneOutlinerOnNextTick();
    }
}

void FOutlineCollapserModule::OnActorSelected(UObject* SelectedObject)
{
    const UOutlineCollapserSettings* Settings = GetDefault<UOutlineCollapserSettings>();
    if (Settings && Settings->bCollapseOnSelection)
    {
        CollapseVisibleSceneOutlinerOnNextTick();
    }
}

void FOutlineCollapserModule::CollapseVisibleSceneOutlinerOnNextTick()
{
    if (GEditor)
    {
        auto Delegate = FTimerDelegate::CreateRaw(this, &FOutlineCollapserModule::CollapseVisibleSceneOutliner);
        GEditor->GetTimerManager()->SetTimerForNextTick(Delegate);
    }
}

void FOutlineCollapserModule::CollapseVisibleSceneOutliner()
{
    TSharedPtr<SSceneOutliner> FoundOutliner = nullptr;
    if (!GetFirstSceneOutliner(FoundOutliner))
        return;

    // Collapse all from root (Level)
    FoundOutliner->CollapseAll();

    // Re-open first item (World/PersistentLevel)?
    const UOutlineCollapserSettings* Settings = GetDefault<UOutlineCollapserSettings>();
    if (Settings && Settings->bKeepRootItemExpanded)
    {
        const TArrayView<const FSceneOutlinerTreeItemPtr> RootItems = FoundOutliner->GetTree().GetRootItems();
        if (RootItems.Num() > 0)
            FoundOutliner->SetItemExpansion(RootItems[0], true);
    }
}

void FOutlineCollapserModule::ExpandParentsOfSelectedItems()
{
    TSharedPtr<SSceneOutliner> Outliner = nullptr;
    if (!GetFirstSceneOutliner(Outliner))
        return;

    const TArray<FSceneOutlinerTreeItemPtr> SelectedItems = Outliner->GetSelectedItems();
    for (const FSceneOutlinerTreeItemPtr& Item : SelectedItems)
    {
        FSceneOutlinerTreeItemPtr CurrentItem = Item;

        while (CurrentItem.IsValid())
        {
            const FSceneOutlinerTreeItemPtr ParentItem = CurrentItem->GetParent();
            if (!ParentItem.IsValid())
                break;

            Outliner->SetItemExpansion(ParentItem, true);
            CurrentItem = ParentItem;
        }
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOutlineCollapserModule, OutlineCollapser)
