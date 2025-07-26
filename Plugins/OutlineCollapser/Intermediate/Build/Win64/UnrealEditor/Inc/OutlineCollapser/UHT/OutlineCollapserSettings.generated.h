// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OutlineCollapserSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OUTLINECOLLAPSER_OutlineCollapserSettings_generated_h
#error "OutlineCollapserSettings.generated.h already included, missing '#pragma once' in OutlineCollapserSettings.h"
#endif
#define OUTLINECOLLAPSER_OutlineCollapserSettings_generated_h

#define FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOutlineCollapserSettings(); \
	friend struct Z_Construct_UClass_UOutlineCollapserSettings_Statics; \
public: \
	DECLARE_CLASS(UOutlineCollapserSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/OutlineCollapser"), NO_API) \
	DECLARE_SERIALIZER(UOutlineCollapserSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Editor");} \



#define FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOutlineCollapserSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOutlineCollapserSettings(UOutlineCollapserSettings&&); \
	UOutlineCollapserSettings(const UOutlineCollapserSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOutlineCollapserSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOutlineCollapserSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOutlineCollapserSettings) \
	NO_API virtual ~UOutlineCollapserSettings();


#define FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_9_PROLOG
#define FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_12_INCLASS_NO_PURE_DECLS \
	FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OUTLINECOLLAPSER_API UClass* StaticClass<class UOutlineCollapserSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OutlineCollapserProj_Plugins_OutlineCollapser_Source_OutlineCollapser_Public_OutlineCollapserSettings_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
