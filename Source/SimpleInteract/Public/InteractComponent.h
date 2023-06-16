// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "InteractComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnToggleInteractabilityDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResetDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetKeysDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHighlightChange, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMovePlayer, AActor*, actorToMove, bool, interactAfter);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIMPLEINTERACT_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Is the button a toggle? or should it reset"))
	bool bIsToggle = false;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "If the button resets should it send another interact when it resets.", EditCondition = "!isToggle"))
	bool bSendResetInteraction = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "How long the interact actor will stay in its new state before reseting to what its default state", EditCondition = "!isToggle"))
	float resetDelay = 0.3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the player need to vaguely face the button"))
	bool bNeedsToFace = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the button start on"))
	bool bStartActive = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the object be highlightable"))
	bool bHighlightAble = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Should the player be moved into postion before activation?"))
	bool bMovePlayerIntoPosition = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (MakeEditWidget = true, ToolTip = "The position to move the player to", EditCondition="movePlayerIntoPosition"))
	FTransform playerPoint;


	//Used if you want to make a UI notification or change how you interact
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Keyword for determing type of interaction"))
	FString interactionType = "none";

	//Called to toggle whether the button is usable
	UFUNCTION(BlueprintCallable, Category = "Player Functionality", meta = (ToolTip = "Toggles the useability of the button"))
	void toggleInteractability();

	UFUNCTION(BlueprintCallable, Category = "Class functionality")
	bool getStatus() { return bIsActivated; }

	UFUNCTION(BlueprintCallable, Category = "Player Functionality")
	void Interact();
	UFUNCTION(BlueprintCallable, Category = "Player Functionality")
	void ToggleHighlight(bool newStatus);
	UFUNCTION(BlueprintCallable, Category = "Player Functionality")
	void moveActorIntoPlace(AActor* actorToMove);

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

	//Usability status
	bool bIsInteractable = true;
	//Activated status
	bool bIsActivated = false;

	//Reset timer and function for non toggle triggers
	FTimerHandle resetTimer;
	UFUNCTION(BlueprintCallable, Category = "Class functionality")
	void resetTrigger();

	//Check if character is facing interactable
	bool characterFacingCheck();
};
