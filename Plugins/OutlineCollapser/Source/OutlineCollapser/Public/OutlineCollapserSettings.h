#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OutlineCollapserSettings.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnSettingsChanged);

UCLASS(config = Editor, defaultconfig)
class OUTLINECOLLAPSER_API UOutlineCollapserSettings : public UObject
{
    GENERATED_BODY()

public:
    /** Collapse on editor startup */
    UPROPERTY(EditAnywhere, config, Category = "Settings")
    bool bCollapseOnStartup = true;

    /** Collapse after selecting an actor */
    UPROPERTY(EditAnywhere, config, Category = "Settings")
    bool bCollapseOnSelection = true;

    /** Collapse after adding an actor */
    UPROPERTY(EditAnywhere, config, Category = "Settings")
    bool bCollapseOnActorDropped = true;

    /** Keeps 1st item (World/Level) expanded */
    UPROPERTY(EditAnywhere, config, Category = "Settings")
    bool bKeepRootItemExpanded = false;

    /** Jump to Selected Actor Hotkey */
    UPROPERTY(EditAnywhere, config, Category = "Jump to Selected Actor Hotkey")
    FKey Hotkey = EKeys::E;

    UPROPERTY(EditAnywhere, config, Category = "Jump to Selected Actor Hotkey")
    bool bCtrlModifier = false;

    UPROPERTY(EditAnywhere, config, Category = "Jump to Selected Actor Hotkey")
    bool bAltModifier = false;

    UPROPERTY(EditAnywhere, config, Category = "Jump to Selected Actor Hotkey")
    bool bShiftModifier = true;

public:
    FOnSettingsChanged& OnSettingChanged() { return SettingChangedEvent; }

    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
    {
        Super::PostEditChangeProperty(PropertyChangedEvent);
        SettingChangedEvent.Broadcast();
    }

private:
    FOnSettingsChanged SettingChangedEvent;
};
