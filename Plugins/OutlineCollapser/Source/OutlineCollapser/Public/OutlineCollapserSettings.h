#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OutlineCollapserSettings.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnSettingsChanged);
DECLARE_MULTICAST_DELEGATE(FOnKeybindChanged);

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

    /** Expand to Selected Actor Hotkey */
    UPROPERTY(EditAnywhere, config, Category = "Expand to Selected Actor Hotkey")
    FKey Hotkey = EKeys::E;

    UPROPERTY(EditAnywhere, config, Category = "Expand to Selected Actor Hotkey")
    bool bCtrlModifier = false;

    UPROPERTY(EditAnywhere, config, Category = "Expand to Selected Actor Hotkey")
    bool bAltModifier = false;

    UPROPERTY(EditAnywhere, config, Category = "Expand to Selected Actor Hotkey")
    bool bShiftModifier = true;

public:
    FOnSettingsChanged& OnSettingChanged() { return SettingChangedEvent; }
    FOnKeybindChanged& OnKeybindChanged() { return KeybindChangedEvent; }

    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
    {
        Super::PostEditChangeProperty(PropertyChangedEvent);

        SettingChangedEvent.Broadcast();

        FProperty* ChangedProperty = PropertyChangedEvent.Property;
        if (ChangedProperty)
        {
            const FName PropertyName = ChangedProperty->GetFName();

            if (PropertyName == GET_MEMBER_NAME_CHECKED(UOutlineCollapserSettings, Hotkey) ||
                PropertyName == GET_MEMBER_NAME_CHECKED(UOutlineCollapserSettings, bCtrlModifier) ||
                PropertyName == GET_MEMBER_NAME_CHECKED(UOutlineCollapserSettings, bAltModifier) ||
                PropertyName == GET_MEMBER_NAME_CHECKED(UOutlineCollapserSettings, bShiftModifier))
            {
                KeybindChangedEvent.Broadcast();
            }
        }
    }

private:
    FOnSettingsChanged SettingChangedEvent;
    FOnKeybindChanged KeybindChangedEvent;
};
