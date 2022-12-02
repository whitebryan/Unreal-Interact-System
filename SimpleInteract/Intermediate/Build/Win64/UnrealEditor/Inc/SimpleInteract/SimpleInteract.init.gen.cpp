// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleInteract_init() {}
	SIMPLEINTERACT_API UFunction* Z_Construct_UDelegateFunction_SimpleInteract_OnGetKeysDelegate__DelegateSignature();
	SIMPLEINTERACT_API UFunction* Z_Construct_UDelegateFunction_SimpleInteract_OnInteractDelegate__DelegateSignature();
	SIMPLEINTERACT_API UFunction* Z_Construct_UDelegateFunction_SimpleInteract_OnResetDelegate__DelegateSignature();
	SIMPLEINTERACT_API UFunction* Z_Construct_UDelegateFunction_SimpleInteract_OnToggleInteractabilityDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SimpleInteract;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SimpleInteract()
	{
		if (!Z_Registration_Info_UPackage__Script_SimpleInteract.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SimpleInteract_OnGetKeysDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SimpleInteract_OnInteractDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SimpleInteract_OnResetDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SimpleInteract_OnToggleInteractabilityDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SimpleInteract",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x06912EC2,
				0xEAAD4263,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SimpleInteract.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SimpleInteract.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SimpleInteract(Z_Construct_UPackage__Script_SimpleInteract, TEXT("/Script/SimpleInteract"), Z_Registration_Info_UPackage__Script_SimpleInteract, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x06912EC2, 0xEAAD4263));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
