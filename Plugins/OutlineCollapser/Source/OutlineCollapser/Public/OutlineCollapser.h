#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "ActorFinalizationWatcher.h" 
#include "SSceneOutliner.h"

class FUICommandList;

class FOutlineCollapserModule : public IModuleInterface
{
public:

    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:

    /** Command list used to bind our hotkey */
    TSharedPtr<FUICommandList> PluginCommands;

    /** Register plugin settings with the editor */
    void RegisterSettings();

    /** Notification for keybind setting changed */
    void OnKeybindChanged();

    /** Rebind new hotkey */
    void RebindCommands();

    /** Gets the current first scene outliner */
    bool GetFirstSceneOutliner(TSharedPtr<SSceneOutliner>& SceneOutliner);

    /** Called when the hotkey is pressed to expand selected actors tree */
    void ExpandParentsOfSelectedItems();

    /** Called when the outliner gets ready */
    void OnTabManagerChanged();

    /** Called when an actor is dropped to the level */
    void OnActorsDropped(const TArray<UObject*>& Objects, const TArray<AActor*>& Actors);

    /** Callback when all dropped actors are finalized */
    void OnDroppedActorsFinalized();

    /** Callbacks when a map is opened in editor */
    void OnMapOpened(const FString& FileName, bool bAsTemplate);

    /** Called when an actor gets selected in editor viewport */
    void OnActorSelected(UObject* SelectedObject);

    /** Collapse all dirs/actors in editor visible outline */
    void CollapseVisibleSceneOutliner();

    /** Register a call to collapse all on next tick */
    void CollapseVisibleSceneOutlinerOnNextTick();

    /** Adds Entry to a menu */
    void AddEntriesToMenu(FMenuBuilder& MenuBuilder);

private:

    TSharedPtr<FActorFinalizationWatcher> FinalizationWatcher;

};
