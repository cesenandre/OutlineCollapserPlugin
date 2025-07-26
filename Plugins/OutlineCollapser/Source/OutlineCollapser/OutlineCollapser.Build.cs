using UnrealBuildTool;

public class OutlineCollapser : ModuleRules
{
    public OutlineCollapser(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "UnrealEd",
            "LevelEditor",
            "Slate",
            "SlateCore",
            "EditorStyle",
            "EditorSubsystem",
            "Projects",
            "Settings",
            "SceneOutliner",
        });

        PrivateIncludePaths.Add("OutlineCollapser/Private");
    }
}
