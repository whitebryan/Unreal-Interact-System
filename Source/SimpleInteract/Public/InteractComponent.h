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
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHighlightChange, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMovePlayer, AActor*, actorToMove, bool, interactAfter);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIMPLEINTERACT_API UInteractComponent : public UActorComponent, public IInteractInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Is the button a toggle? or should it reset"))
	bool isToggle = false;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "If the button resets should it send another interact when it resets.", EditCondition = "!isToggle"))
	bool sendResetInteraction = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "How long the interact actor will stay in its new state before reseting to what its default state", EditCondition = "!isToggle"))
	float resetDelay = 0.3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the player need to vaguely face the button"))
	bool needsToFace = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the button start on"))
	bool startActive = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the object be highlightable"))
	bool highlightAble = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the player be moved into postion before activation?"))
	bool movePlayerIntoPosition = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (MakeEditWidget = true, ToolTip = "The position to move the player to", EditCondition="movePlayerIntoPosition"))
	FTransform playerPoint;


	//Used if you want to make a UI notification or change how you interact
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Keyword for determing type of interaction"))
	FString interactionType = "none";

	//Called to toggle whether the button is useable
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Player Functionality", meta = (ToolTip = "Toggles the useability of the button"))
	void toggleInteractability();

	UFUNCTION(BlueprintCallable, Category = "Class functionality")
	bool getStatus() { return isActivated; }

	//Delegates
	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnToggleInteractabilityDelegate OnToggleInteractability;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnInteractDelegate OnInteract;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnResetDelegate OnReset;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnHighlightChange OnHighlight;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnMovePlayer PlayerNeedsToMove;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Used to temperoraily disable a trigger
	bool isInteractable = true;
	//Activated status
	bool isActivated = false;
	//Highlight status

	//Reset timer and function for non toggle triggers
	FTimerHandle resetTimer;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Class functionality")
	void resetTrigger();

	//Check if character is facing interactable
	bool characterFacingCheck();

	//Interact interface reciever
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player Functionality")
	void Interact(); virtual void Interact_Implementation() override;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player Functionality")
	void ToggleHighlight(bool newStatus); virtual void ToggleHighlight_Implementation(bool newStatus) override;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player Functionality")
	void moveActorIntoPlace(AActor* actorToMove); virtual void moveActorIntoPlace_Implementation(AActor* actorToMove) override;
};
