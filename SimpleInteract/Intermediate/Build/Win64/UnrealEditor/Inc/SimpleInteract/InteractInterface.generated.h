// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLEINTERACT_InteractInterface_generated_h
#error "InteractInterface.generated.h already included, missing '#pragma once' in InteractInterface.h"
#endif
#define SIMPLEINTERACT_InteractInterface_generated_h

#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_SPARSE_DATA
#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_RPC_WRAPPERS \
	virtual void Interact_Implementation() {}; \
 \
	DECLARE_FUNCTION(execInteract);


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Interact_Implementation() {}; \
 \
	DECLARE_FUNCTION(execInteract);


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_EVENT_PARMS
#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_CALLBACK_WRAPPERS
#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SIMPLEINTERACT_API UInteractInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SIMPLEINTERACT_API, UInteractInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SIMPLEINTERACT_API UInteractInterface(UInteractInterface&&); \
	SIMPLEINTERACT_API UInteractInterface(const UInteractInterface&); \
public:


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SIMPLEINTERACT_API UInteractInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SIMPLEINTERACT_API UInteractInterface(UInteractInterface&&); \
	SIMPLEINTERACT_API UInteractInterface(const UInteractInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SIMPLEINTERACT_API, UInteractInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractInterface)


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractInterface(); \
	friend struct Z_Construct_UClass_UInteractInterface_Statics; \
public: \
	DECLARE_CLASS(UInteractInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/SimpleInteract"), SIMPLEINTERACT_API) \
	DECLARE_SERIALIZER(UInteractInterface)


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractInterface() {} \
public: \
	typedef UInteractInterface UClassType; \
	typedef IInteractInterface ThisClass; \
	static void Execute_Interact(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IInteractInterface() {} \
public: \
	typedef UInteractInterface UClassType; \
	typedef IInteractInterface ThisClass; \
	static void Execute_Interact(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_10_PROLOG \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_EVENT_PARMS


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_SPARSE_DATA \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_RPC_WRAPPERS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_SPARSE_DATA \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMPLEINTERACT_API UClass* StaticClass<class UInteractInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_SimpleInteract_Source_SimpleInteract_Public_InteractInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
