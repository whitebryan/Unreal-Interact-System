// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowSplineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UFollowSplineComponent::UFollowSplineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetComponentTickInterval(0);
	SetTickGroup(ETickingGroup::TG_PrePhysics);
	interactComp = CreateDefaultSubobject<UInteractComponent>(TEXT("Interaction Component"));
	interactComp->bIsToggle = true;
	interactComp->bSendResetInteraction = false;
	interactComp->bNeedsToFace = false;

	// ...
}


// Called when the game starts
void UFollowSplineComponent::BeginPlay()
{
	Super::BeginPlay();

	interactComp->OnInteract.AddDynamic(this, &UFollowSplineComponent::Interact);

	//Grab out spline and static mesh from parent
	splineToFollow = Cast<USplineComponent>(GetOwner()->GetComponentByClass(USplineComponent::StaticClass()));

	curSpeed = moveSpeed;

	numPoints = splineToFollow->GetNumberOfSplinePoints();
	if (GetWorld())
	{
		//If it should be active on start or not
		if (bStartActivated && bShouldDistancePause)
		{
			GetWorld()->GetTimerManager().SetTimer(distanceChecker, this, &UFollowSplineComponent::distanceCheck, checkIncrement, true);
		}
		else if(!bStartActivated)
		{
			SetComponentTickEnabled(false);
		}

		//Delay first movement or not
		if (bStartDelayed)
		{
			GetWorld()->GetTimerManager().SetTimer(endDelayer, this, &UFollowSplineComponent::toggleDelay, stopDelay, false);
		}
		else
		{
			toggleDelay();
		}
	}
}

//end delay
void UFollowSplineComponent::toggleDelay()
{
	bIsDelayed = false;
}


// Called every frame
void UFollowSplineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!bIsDelayed)
	{
		//Check if we are currently nearly at a spline point
		bool atPoint = objectToMove->GetRelativeLocation().Equals(splineToFollow->GetLocationAtSplinePoint(nextPoint, ESplineCoordinateSpace::Local), 5);

		if (atPoint)
		{
			if (splineToFollow->IsClosedLoop() && nextPoint >= numPoints)//Reset to 0 after a loop in a closed loop
			{
				nextPoint = 0;
			}
			else if (splineToFollow->IsClosedLoop())
			{
				++nextPoint;
			}
			else if(!splineToFollow->IsClosedLoop())
			{
				if (nextPoint >= numPoints)//change direction to go backwards in a non closed loop
				{
					pointChange = -1;

					nextPoint += pointChange;

					if (bShouldEverStop && !bStopAtSplinePoints)
					{
						bIsDelayed = true;
						GetWorld()->GetTimerManager().SetTimer(endDelayer, this, &UFollowSplineComponent::toggleDelay, stopDelay, false);
						return;
					}
				}
				else if (nextPoint < 0)//Change direction to go forward again in non closed loop
				{
					pointChange = 1;

					nextPoint += pointChange;

					if (bShouldEverStop && !bStopAtSplinePoints)
					{
						bIsDelayed = true;
						GetWorld()->GetTimerManager().SetTimer(endDelayer, this, &UFollowSplineComponent::toggleDelay, stopDelay, false);
						return;
					}
				}
				else
				{
					nextPoint += pointChange;
				}
			}

			if (bShouldEverStop && bStopAtSplinePoints)//Pause if the spline is meant to stop
			{
				bIsDelayed = true;
				GetWorld()->GetTimerManager().SetTimer(endDelayer, this, &UFollowSplineComponent::toggleDelay, stopDelay, false);
				return;
			}
		}


		//Interp towards next point
		FVector newLoc = UKismetMathLibrary::VInterpTo_Constant(objectToMove->GetRelativeLocation(), splineToFollow->GetLocationAtSplinePoint(nextPoint, ESplineCoordinateSpace::Local), GetWorld()->GetDeltaSeconds(), curSpeed);


		if (bShouldRotate)//Get the cur dist on spline then rotate the platform if it should
		{
			FVector pos;
			float curDist = splineToFollow->FindInputKeyClosestToWorldLocation(objectToMove->GetComponentLocation());
			curDist = splineToFollow->GetDistanceAlongSplineAtSplineInputKey(curDist);
			FRotator newRot = splineToFollow->GetRotationAtDistanceAlongSpline(curDist, ESplineCoordinateSpace::World);

			objectToMove->SetWorldRotation(newRot);
		}

		objectToMove->SetRelativeLocation(newLoc);
	}
}


//Enable or disable the movement
void UFollowSplineComponent::Interact(bool bStatus)
{
	if (bStatus)
	{
		if (bShouldDistancePause)
		{
			GetWorld()->GetTimerManager().SetTimer(distanceChecker, this, &UFollowSplineComponent::distanceCheck, checkIncrement, true);
		}

		SetComponentTickEnabled(true);
	}
	else
	{
		if (bShouldDistancePause)
		{
			GetWorld()->GetTimerManager().ClearTimer(distanceChecker);
		}
		SetComponentTickEnabled(false);
	}
}

//Checking our distance to the player and disabled or enabling if they are out/in range
void UFollowSplineComponent::distanceCheck()
{
	APawn* player = nullptr;
	AActor* owner = GetOwner();

	if (GetWorld())
	{
		player = GetWorld()->GetFirstPlayerController()->GetPawn();
	}
	else
		return;

	if (player == nullptr || owner == nullptr)
		return;

	float distance = UKismetMathLibrary::Vector_Distance(objectToMove->GetComponentLocation(), player->GetActorLocation());
	if (UKismetMathLibrary::Abs(distance) >= distTillPause)
	{
		SetComponentTickEnabled(false);
	}
	else if (!PrimaryComponentTick.IsTickFunctionEnabled())
		SetComponentTickEnabled(true);
}