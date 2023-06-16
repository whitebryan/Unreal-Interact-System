// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"
#include "GameFramework/Character.h" 

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
}

// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	if (bStartActive)
	{
		Interact();
	}
}

//Toggle the useability of the component 
void UInteractComponent::toggleInteractability()
{
	bIsInteractable = !bIsInteractable;
	OnToggleInteractability.Broadcast(bIsInteractable);
}

//Main interaction function
void UInteractComponent::Interact()
{
	if (bIsInteractable)
	{
		if (bNeedsToFace && !characterFacingCheck())
		{
			return;
		}

		bIsActivated = !bIsActivated;

		if (bMovePlayerIntoPosition)
		{
			PlayerNeedsToMove.Broadcast(Cast<AActor>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)), true);
		}
		else
		{
			OnInteract.Broadcast(bIsActivated);
		}

		//If the button isnt a toggle start a timer till it should reset
		if (!bIsToggle)
		{
			if (GetWorld())
			{
				float timerDelay = resetDelay;

				//Add time to the delay if the player needs to move first, currenly hardcoded basedd off a 1 second timer to move the player
				if (bMovePlayerIntoPosition)
				{
					timerDelay += 1;
				}

				GetWorld()->GetTimerManager().SetTimer(resetTimer, this, &UInteractComponent::resetTrigger, timerDelay, false);
			}
		}
	}
}

void UInteractComponent::ToggleHighlight(bool status)
{
	if (bHighlightAble)
	{
		OnHighlight.Broadcast(status);
	}
}

//Reset function
void UInteractComponent::resetTrigger()
{
	bIsActivated = !bIsActivated;

	if (bSendResetInteraction)
	{
		//Reset and interact again
		OnInteract.Broadcast(bIsActivated);
	}
	else
	{
		//Reset status without interacting again
		OnReset.Broadcast(bIsActivated);
	}
}

//Check if the first player controllers pawn is facing the button
bool UInteractComponent::characterFacingCheck()
{
	APawn* playerPawn;

	if (GetWorld())
	{
		playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (IsValid(playerPawn))
		{
			float heading = (GetOwner()->GetActorLocation() - playerPawn->GetActorLocation()).GetSafeNormal().Dot(playerPawn->GetActorForwardVector());
			UKismetSystemLibrary::PrintWarning(FString::SanitizeFloat(heading));
			if (heading > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}


//Used if you want to seperately move and interact
void UInteractComponent::moveActorIntoPlace(AActor* actorToMove)
{
	PlayerNeedsToMove.Broadcast(actorToMove, false);
}