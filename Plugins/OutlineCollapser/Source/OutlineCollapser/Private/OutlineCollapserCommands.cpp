#include "OutlineCollapserCommands.h"
#include "OutlineCollapserSettings.h"

#define LOCTEXT_NAMESPACE "FOutlineCollapserModule"

void FOutlineCollapserCommands::RegisterCommands()
{
    const UOutlineCollapserSettings* Settings = GetDefault<UOutlineCollapserSettings>();

    FInputChord CustomChord(
        Settings->Hotkey,
        (Settings->bCtrlModifier ? EModifierKey::Control : EModifierKey::None) |
        (Settings->bAltModifier ? EModifierKey::Alt : EModifierKey::None) |
        (Settings->bShiftModifier ? EModifierKey::Shift : EModifierKey::None)
    );

    UI_COMMAND
    (
        ExpandParentsOfSelectedItems,
        "Expand Parents Of Selected Items",
        "Expand Parents Of Selected Items",
        EUserInterfaceActionType::Button,
        CustomChord
    );
}

#undef LOCTEXT_NAMESPACE
