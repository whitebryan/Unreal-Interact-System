// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractInterface.h"
#include "Kismet/GameplayStatics.h"
#include "InteractComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnToggleInteractabilityDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractDelegate, bool, Status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetKeysDelegate, bool, Status);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UInteractComponent : public UActorComponent, public IInteractInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "How long in seconds before the button auto resets to default state"))
	float resetDelay = 0.f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties")
	bool autoActivate = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Is the button a toggle or does it reset"))
	bool isToggle = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Player needs to vaugely be facing the button"))
	bool needsToFace = false;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Keycode required"))
	int keyCode = -1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact Properties", meta = (ToolTip = "Keyword for interaction text to show."))
	FString interactionType = "none";

	UPROPERTY(BlueprintReadWrite)
	TArray<int32> curKeys;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void toggleInteractability();

	//Delegates
	UPROPERTY(BlueprintAssignable, Category = "Delegates", meta = (ToolTip = "Toggle interactable useability"))
	FOnToggleInteractabilityDelegate OnToggleInteractability;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates", meta = (ToolTip = "Delegate used to make Interaction functionality, like changing a button color, in BP if you want it"))
	FOnInteractDelegate OnInteract;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates", meta = (ToolTip = "Delegate used to grab keys from player in some form, I use it to simply cast to my player and grab an array atm"))
	FOnGetKeysDelegate GetKeys;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Used to temperoraily disable a trigger
	bool isInteractable = true;
	//Activated status
	bool isActivated = false;
	bool requiresKey = false;

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