// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLEINTERACT_InteractComponent_generated_h
#error "InteractComponent.generated.h already included, missing '#pragma once' in InteractComponent.h"
#endif
#define SIMPLEINTERACT_InteractComponent_generated_h

#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_11_DELEGATE \
struct _Script_SimpleInteract_eventOnToggleInteractabilityDelegate_Parms \
{ \
	bool Status; \
}; \
static inline void FOnToggleInteractabilityDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnToggleInteractabilityDelegate, bool Status) \
{ \
	_Script_SimpleInteract_eventOnToggleInteractabilityDelegate_Parms Parms; \
	Parms.Status=Status ? true : false; \
	OnToggleInteractabilityDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_12_DELEGATE \
struct _Script_SimpleInteract_eventOnInteractDelegate_Parms \
{ \
	bool Status; \
}; \
static inline void FOnInteractDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnInteractDelegate, bool Status) \
{ \
	_Script_SimpleInteract_eventOnInteractDelegate_Parms Parms; \
	Parms.Status=Status ? true : false; \
	OnInteractDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_13_DELEGATE \
struct _Script_SimpleInteract_eventOnResetDelegate_Parms \
{ \
	bool Status; \
}; \
static inline void FOnResetDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnResetDelegate, bool Status) \
{ \
	_Script_SimpleInteract_eventOnResetDelegate_Parms Parms; \
	Parms.Status=Status ? true : false; \
	OnResetDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_14_DELEGATE \
struct _Script_SimpleInteract_eventOnGetKeysDelegate_Parms \
{ \
	bool Status; \
}; \
static inline void FOnGetKeysDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnGetKeysDelegate, bool Status) \
{ \
	_Script_SimpleInteract_eventOnGetKeysDelegate_Parms Parms; \
	Parms.Status=Status ? true : false; \
	OnGetKeysDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_SPARSE_DATA
#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_RPC_WRAPPERS \
	virtual void Interact_Implementation(); \
	virtual void resetTrigger_Implementation(); \
	virtual void toggleInteractability_Implementation(); \
 \
	DECLARE_FUNCTION(execInteract); \
	DECLARE_FUNCTION(execresetTrigger); \
	DECLARE_FUNCTION(execgetStatus); \
	DECLARE_FUNCTION(exectoggleInteractability);


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void resetTrigger_Implementation(); \
	virtual void toggleInteractability_Implementation(); \
 \
	DECLARE_FUNCTION(execInteract); \
	DECLARE_FUNCTION(execresetTrigger); \
	DECLARE_FUNCTION(execgetStatus); \
	DECLARE_FUNCTION(exectoggleInteractability);


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_EVENT_PARMS
#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_CALLBACK_WRAPPERS
#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInteractComponent(); \
	friend struct Z_Construct_UClass_UInteractComponent_Statics; \
public: \
	DECLARE_CLASS(UInteractComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SimpleInteract"), NO_API) \
	DECLARE_SERIALIZER(UInteractComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UInteractComponent*>(this); }


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUInteractComponent(); \
	friend struct Z_Construct_UClass_UInteractComponent_Statics; \
public: \
	DECLARE_CLASS(UInteractComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SimpleInteract"), NO_API) \
	DECLARE_SERIALIZER(UInteractComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UInteractComponent*>(this); }


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInteractComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInteractComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInteractComponent(UInteractComponent&&); \
	NO_API UInteractComponent(const UInteractComponent&); \
public:


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInteractComponent(UInteractComponent&&); \
	NO_API UInteractComponent(const UInteractComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInteractComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInteractComponent)


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_16_PROLOG \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_EVENT_PARMS


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_SPARSE_DATA \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_RPC_WRAPPERS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_INCLASS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_SPARSE_DATA \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMPLEINTERACT_API UClass* StaticClass<class UInteractComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
