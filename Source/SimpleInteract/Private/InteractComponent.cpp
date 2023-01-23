// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
}

// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
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

		if (movePlayerIntoPosition)
		{
			PlayerNeedsToMove.Broadcast();
		}
		else
		{
			OnInteract.Broadcast(isActivated);
		}

		//If the button isnt a toggle start a timer till it should reset
		if (!isToggle)
		{
			if (GetWorld())
			{
				float timerDelay = resetDelay;

				//Add time to the delay if the player needs to move first, currenly hardcoded basedd off a 1 second timer to move the player
				if (movePlayerIntoPosition)
				{
					timerDelay += 1;
				}

				GetWorld()->GetTimerManager().SetTimer(resetTimer, this, &UInteractComponent::resetTrigger_Implementation, timerDelay, false);
			}
		}
	}
}

void UInteractComponent::ToggleHighlight_Implementation(bool status)
{
	if (highlightAble)
	{
		OnHighlight.Broadcast(status);
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
