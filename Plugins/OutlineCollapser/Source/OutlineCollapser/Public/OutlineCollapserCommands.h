#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "Styling/AppStyle.h"

class FOutlineCollapserCommands : public TCommands<FOutlineCollapserCommands>
{
public:
    FOutlineCollapserCommands()
        : TCommands<FOutlineCollapserCommands>(
            TEXT("OutlineCollapser"),
            NSLOCTEXT("Contexts", "OutlineCollapser", "Outline Collapser Plugin"),
            NAME_None,
            FAppStyle::GetAppStyleSetName()
        ) {}

    virtual void RegisterCommands() override;

    TSharedPtr<FUICommandInfo> ExpandParentsOfSelectedItems;
};
