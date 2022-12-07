// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
}

// Called when the game starts
void UInteractComponent::BeginPlay()
{
	if (startActive)
	{
		Interact();
	}
}

//Toggle the useability of the component 
void UInteractComponent::toggleInteractability_Implementation()
{
	isInteractable = !isInteractable;
	OnToggleInteractability.Broadcast(isInteractable);
}

//Main interaction function
void UInteractComponent::Interact_Implementation()
{
	if (needsToFace && !characterFacingCheck())
	{
		return;
	}
	else if (isInteractable)
	{
		isActivated = !isActivated;
		OnInteract.Broadcast(isActivated);

		//If the button isnt a toggle start a timer till it should reset
		if (!isToggle)
		{
			if (GetWorld())
			{
				GetWorld()->GetTimerManager().SetTimer(resetTimer, this, &UInteractComponent::resetTrigger_Implementation, resetDelay, false);
			}
		}
	}
}

//Reset function
void UInteractComponent::resetTrigger_Implementation()
{
	isActivated = !isActivated;

	if (sendResetInteraction)
	{
		OnInteract.Broadcast(isActivated);
	}
	else
	{
		OnReset.Broadcast(isActivated);
	}
}

//Check if the first player controllers pawn is facing the button
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
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}
