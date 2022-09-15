// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractInterface.h"
#include "Kismet/GameplayStatics.h"
#include "InteractComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnToggleInteractabilityDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResetDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetKeysDelegate, bool, Status);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIMPLEINTERACT_API UInteractComponent : public UActorComponent, public IInteractInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Is the button a toggle? or should it reset"))
	bool isToggle = false;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "If the button resets should it send another interact when it resets."))
	bool sendResetInteraction = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "How long the interact actor will stay in its new state before reseting to what its default state"))
	float resetDelay = 0.3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the player need to vaguely face the button"))
	bool needsToFace = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the button start on"))
	bool startActive = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Keyword for interaction text to show."))
	FString interactionType = "none";

	UPROPERTY(BlueprintReadWrite)
	TArray<int32> curKeys;

	//Called to toggle whether the button is useable
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, meta = (ToolTip = "Toggles the useability of the button"))
	void toggleInteractability();

	//Delegates
	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnToggleInteractabilityDelegate OnToggleInteractability;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnInteractDelegate OnInteract;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnGetKeysDelegate GetKeys;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnResetDelegate OnReset;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Used to temperoraily disable a trigger
	bool isInteractable = true;
	//Activated status
	bool isActivated = false;

	//Reset timer and function for non toggle triggers
	FTimerHandle resetTimer;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void resetTrigger();

	//Check if character is facing interactable
	bool characterFacingCheck();

	//Interact interface reciever
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(); virtual void Interact_Implementation() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;		
};
