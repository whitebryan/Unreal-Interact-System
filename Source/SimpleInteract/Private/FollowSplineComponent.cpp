// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowSplineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UFollowSplineComponent::UFollowSplineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFollowSplineComponent::BeginPlay()
{
	Super::BeginPlay();

	//Grab out spline and static mesh from parent
	splineToFollow = Cast<USplineComponent>(GetOwner()->GetComponentByClass(USplineComponent::StaticClass()));
	objectToMove = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));

	curSpeed = moveSpeed;
	if (GetWorld())
	{
		//If it should be active on start or not
		if (startActivated)
		{
			GetWorld()->GetTimerManager().SetTimer(distanceChecker, this, &UFollowSplineComponent::distanceCheck, checkIncrement, true);
		}
		else
		{
			SetComponentTickEnabled(false);
		}

		//Delay first movement or not
		if (startDelayed)
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
	isDelayed = false;
}


// Called every frame
void UFollowSplineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!isDelayed)
	{
		//Reset distance on spline to 0 once a closed loop has done a full rotation
		if (splineToFollow->IsClosedLoop() && curDistanceOnSpline > 0 && splineToFollow->GetLocationAtDistanceAlongSpline(0, ESplineCoordinateSpace::Local).Equals(objectToMove->GetRelativeLocation(),3))
		{
			curDistanceOnSpline = 0;
		}
		else if (!splineToFollow->IsClosedLoop() && (curDistanceOnSpline <= 0 || (stopAtSplinePoints && lastPoint == 0 && objectToMove->GetRelativeLocation().Equals(splineToFollow->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::Local), 5))))//Flip move direction for non closed loops and delay if not using stop at spline points
		{
			curSpeed = moveSpeed;
			curDistanceOnSpline = 0.01f;

			isDelayed = true;
			GetWorld()->GetTimerManager().SetTimer(endDelayer, this, &UFollowSplineComponent::toggleDelay, stopDelay, false);
			if (stopAtSplinePoints)
			{
				lastPoint += 1;
			}
			return;
		}
		else if (!splineToFollow->IsClosedLoop() && (curDistanceOnSpline >= splineToFollow->GetSplineLength() || (stopAtSplinePoints && lastPoint == splineToFollow->GetNumberOfSplinePoints()))) //Flip move direction for non closed loops and delay if not using stop at spline points
		{
			curSpeed = moveSpeed * -1;
			curDistanceOnSpline = splineToFollow->GetSplineLength() - 0.01f;
			
			if (!stopAtSplinePoints)
			{
				isDelayed = true;
				GetWorld()->GetTimerManager().SetTimer(endDelayer, this, &UFollowSplineComponent::toggleDelay, stopDelay, false);
			}
			else
			{
				lastPoint -= 1;
			}

			return;
		}
		
		if (stopAtSplinePoints)//Check if we are near a point when using stop at spline points
		{
			int numPoints = splineToFollow->GetNumberOfSplinePoints();
			if (splineToFollow->IsClosedLoop() && lastPoint >= numPoints)
			{
				lastPoint = 0;
			}
			else
			{
				FVector nextPointLoc = splineToFollow->GetLocationAtSplinePoint(lastPoint, ESplineCoordinateSpace::Local);
				if (objectToMove->GetRelativeLocation().Equals(nextPointLoc, 5))
				{
					if (splineToFollow->IsClosedLoop())
					{
						++lastPoint;
					}
					else
					{
						lastPoint += UKismetMathLibrary::SignOfFloat(curSpeed);
					}

					isDelayed = true;
					GetWorld()->GetTimerManager().SetTimer(endDelayer, this, &UFollowSplineComponent::toggleDelay, stopDelay, false);
					return;
				}
			}
		}

		//Move platform
		curDistanceOnSpline += (curSpeed * DeltaTime);
		FVector newLoc = splineToFollow->GetLocationAtDistanceAlongSpline(curDistanceOnSpline, ESplineCoordinateSpace::Local);
		objectToMove->SetRelativeLocation(newLoc);
	}
}


//Enable or disable the movement
void UFollowSplineComponent::Interact_Implementation()
{
	if (!status)
	{
		GetWorld()->GetTimerManager().SetTimer(distanceChecker, this, &UFollowSplineComponent::distanceCheck, checkIncrement, true);
		SetComponentTickEnabled(true);
		status = true;
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(distanceChecker);
		SetComponentTickEnabled(false);
		status = false;
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

	float distance = UKismetMathLibrary::Vector_Distance(GetOwner()->GetActorLocation(), player->GetActorLocation());
	if (UKismetMathLibrary::Abs(distance) >= distTillPause)
	{
		SetComponentTickEnabled(false);
	}
	else if (!PrimaryComponentTick.IsTickFunctionEnabled())
		SetComponentTickEnabled(true);
}