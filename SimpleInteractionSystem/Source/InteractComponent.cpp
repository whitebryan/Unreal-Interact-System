// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UInteractComponent::toggleInteractability_Implementation()
{
	isInteractable = !isInteractable;
	OnToggleInteractability.Broadcast(isInteractable);
}


// Called when the game starts
void UInteractComponent::BeginPlay()
{
	if (keyCode != -1)
		requiresKey = true;	
}

void UInteractComponent::Interact_Implementation()
{
	if (needsToFace && !characterFacingCheck())
		return;
	if (isInteractable)
	{
		if (requiresKey)
		{
			GetKeys.Broadcast(true);
			if (!curKeys.Contains(keyCode))
			{
				return;
			}
		}

		isActivated = !isActivated;
		OnInteract.Broadcast(isActivated);
		if (!isToggle)
		{
			if (GetWorld())
			{
				GetWorld()->GetTimerManager().SetTimer(resetTimer, this, &UInteractComponent::resetTrigger_Implementation, resetDelay, false);
			}
		}
	}
}
void UInteractComponent::resetTrigger_Implementation()
{
	isActivated = !isActivated;
	
	//OnInteract.Broadcast(isActivated);

	if (sendResetInteraction)
		OnInteract.Broadcast(isActivated);
	else
		OnReset.Broadcast(isActivated);
}

bool UInteractComponent::characterFacingCheck()
{
	APawn* playerPawn;

	if (GetWorld())
	{
		playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (playerPawn == NULL)
			return false;
		else
		{
			if (playerPawn->GetActorForwardVector().Dot(GetOwner()->GetActorForwardVector()) <= -0.5)
			{
				return true;
			}
			else
				return false;
		}
	}
	else
		return false;
}

//// Called every frame
//void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

