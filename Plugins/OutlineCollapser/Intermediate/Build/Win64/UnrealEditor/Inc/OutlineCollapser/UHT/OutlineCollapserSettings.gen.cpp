// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OutlineCollapser/Public/OutlineCollapserSettings.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOutlineCollapserSettings() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
OUTLINECOLLAPSER_API UClass* Z_Construct_UClass_UOutlineCollapserSettings();
OUTLINECOLLAPSER_API UClass* Z_Construct_UClass_UOutlineCollapserSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_OutlineCollapser();
// End Cross Module References

// Begin Class UOutlineCollapserSettings
void UOutlineCollapserSettings::StaticRegisterNativesUOutlineCollapserSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOutlineCollapserSettings);
UClass* Z_Construct_UClass_UOutlineCollapserSettings_NoRegister()
{
	return UOutlineCollapserSettings::StaticClass();
}
struct Z_Construct_UClass_UOutlineCollapserSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "OutlineCollapserSettings.h" },
		{ "ModuleRelativePath", "Public/OutlineCollapserSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCollapseOnStartup_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Collapse all folders on editor startup */" },
#endif
		{ "ModuleRelativePath", "Public/OutlineCollapserSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collapse all folders on editor startup" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCollapseOnSelection_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Collapse folders again after selecting an actor */" },
#endif
		{ "ModuleRelativePath", "Public/OutlineCollapserSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collapse folders again after selecting an actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bKeepRootItemExpanded_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keeps 1st item (World/Level) expanded */" },
#endif
		{ "ModuleRelativePath", "Public/OutlineCollapserSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps 1st item (World/Level) expanded" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hotkey_MetaData[] = {
		{ "Category", "Jump to Selected Actor Hotkey" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump to Selected Actor Hotkey */" },
#endif
		{ "ModuleRelativePath", "Public/OutlineCollapserSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump to Selected Actor Hotkey" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCtrlModifier_MetaData[] = {
		{ "Category", "Jump to Selected Actor Hotkey" },
		{ "ModuleRelativePath", "Public/OutlineCollapserSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAltModifier_MetaData[] = {
		{ "Category", "Jump to Selected Actor Hotkey" },
		{ "ModuleRelativePath", "Public/OutlineCollapserSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShiftModifier_MetaData[] = {
		{ "Category", "Jump to Selected Actor Hotkey" },
		{ "ModuleRelativePath", "Public/OutlineCollapserSettings.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bCollapseOnStartup_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCollapseOnStartup;
	static void NewProp_bCollapseOnSelection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCollapseOnSelection;
	static void NewProp_bKeepRootItemExpanded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bKeepRootItemExpanded;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hotkey;
	static void NewProp_bCtrlModifier_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCtrlModifier;
	static void NewProp_bAltModifier_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAltModifier;
	static void NewProp_bShiftModifier_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShiftModifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOutlineCollapserSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCollapseOnStartup_SetBit(void* Obj)
{
	((UOutlineCollapserSettings*)Obj)->bCollapseOnStartup = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCollapseOnStartup = { "bCollapseOnStartup", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOutlineCollapserSettings), &Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCollapseOnStartup_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCollapseOnStartup_MetaData), NewProp_bCollapseOnStartup_MetaData) };
void Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCollapseOnSelection_SetBit(void* Obj)
{
	((UOutlineCollapserSettings*)Obj)->bCollapseOnSelection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCollapseOnSelection = { "bCollapseOnSelection", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOutlineCollapserSettings), &Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCollapseOnSelection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCollapseOnSelection_MetaData), NewProp_bCollapseOnSelection_MetaData) };
void Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bKeepRootItemExpanded_SetBit(void* Obj)
{
	((UOutlineCollapserSettings*)Obj)->bKeepRootItemExpanded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bKeepRootItemExpanded = { "bKeepRootItemExpanded", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOutlineCollapserSettings), &Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bKeepRootItemExpanded_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bKeepRootItemExpanded_MetaData), NewProp_bKeepRootItemExpanded_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_Hotkey = { "Hotkey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOutlineCollapserSettings, Hotkey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hotkey_MetaData), NewProp_Hotkey_MetaData) }; // 658672854
void Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCtrlModifier_SetBit(void* Obj)
{
	((UOutlineCollapserSettings*)Obj)->bCtrlModifier = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCtrlModifier = { "bCtrlModifier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOutlineCollapserSettings), &Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCtrlModifier_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCtrlModifier_MetaData), NewProp_bCtrlModifier_MetaData) };
void Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bAltModifier_SetBit(void* Obj)
{
	((UOutlineCollapserSettings*)Obj)->bAltModifier = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bAltModifier = { "bAltModifier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOutlineCollapserSettings), &Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bAltModifier_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAltModifier_MetaData), NewProp_bAltModifier_MetaData) };
void Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bShiftModifier_SetBit(void* Obj)
{
	((UOutlineCollapserSettings*)Obj)->bShiftModifier = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bShiftModifier = { "bShiftModifier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOutlineCollapserSettings), &Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bShiftModifier_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShiftModifier_MetaData), NewProp_bShiftModifier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOutlineCollapserSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCollapseOnStartup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCollapseOnSelection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bKeepRootItemExpanded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_Hotkey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bCtrlModifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bAltModifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOutlineCollapserSettings_Statics::NewProp_bShiftModifier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOutlineCollapserSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOutlineCollapserSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OutlineCollapser,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOutlineCollapserSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOutlineCollapserSettings_Statics::ClassParams = {
	&UOutlineCollapserSettings::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOutlineCollapserSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOutlineCollapserSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOutlineCollapserSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UOutlineCollapserSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOutlineCollapserSettings()
{
	if (!Z_Registration_Info_UClass_UOutlineCollapserSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOutlineCollapserSettings.OuterSingleton, Z_Construct_UClass_UOutlineCollapserSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOutlineCollapserSettings.OuterSingleton;
}
template<> OUTLINECOLLAPSER_API UClass* StaticClass<UOutlineCollapserSettings>()
{
	return UOutlineCollapserSettings::StaticClass();
}
UOutlineCollapserSettings::UOutlineCollapserSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOutlineCollapserSettings);
UOutlineCollapserSettings::~UOutlineCollapserSettings() {}
// End Class UOutlineCollapserSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOutlineCollapserSettings, UOutlineCollapserSettings::StaticClass, TEXT("UOutlineCollapserSettings"), &Z_Registration_Info_UClass_UOutlineCollapserSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOutlineCollapserSettings), 1292525084U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_1063025600(TEXT("/Script/OutlineCollapser"),
	Z_CompiledInDeferFile_FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
