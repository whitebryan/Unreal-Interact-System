// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SplineComponent.h" 
#include "InteractInterface.h"
#include "FollowSplineComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SIMPLEINTERACT_API UFollowSplineComponent : public UActorComponent, public IInteractInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFollowSplineComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Checking distance to player
	FTimerHandle distanceChecker;
	void distanceCheck();

	//End Delay
	FTimerHandle endDelayer;

	UPROPERTY(BlueprintReadOnly)
	bool isDelayed = true;

	//Movement
	UPROPERTY(BlueprintReadOnly)
	int nextPoint = 1;
	int pointChange = 1;
	int numPoints = 0;

	//Used if I later want to slow/speed up at certain points
	float curSpeed;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Performance
	UPROPERTY(EditAnywhere, Category = "Performance")
	bool shouldDistancePause = true;
	UPROPERTY(EditAnywhere, Category = "Performance", meta = (Tooltip = "Distance till the movement is paused", EditCondition = "shouldDistancePause"))
	float distTillPause = 10000;
	UPROPERTY(EditAnywhere, Category = "Performance", meta = (Tooltip = "How often to check distance to player", EditCondition = "shouldDistancePause"))
	float checkIncrement = 3;

	//Movement variables
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Movement")
	bool startActivated = true;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Movement")
	bool startDelayed = true;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (ToolTip = "Speed the object should move.(multiplied by delta time) If you set this too high stopAtSplinePoints will not work"))
	float moveSpeed = 200;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Movement")
	bool shouldRotate = false;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (ToolTip = "Should the object ever stop at points or ends"))
	bool shouldEverStop = true;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (ToolTip = "Stop at spline points or just ends. Not This is require for delays in a closed loop spline", EditCondition = "delayAtEnds"))
	bool stopAtSplinePoints = false;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (ToolTip = "How long to pause at the ends", EditCondition = "delayAtEnds"))
	float stopDelay = 3;

	//Object Ptrs
	UPROPERTY(BlueprintReadWrite, Category = "Pointers")
	USplineComponent* splineToFollow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointers")
	UStaticMeshComponent* objectToMove;

	bool status = false;

	//Interactibility
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(); virtual void Interact_Implementation() override;

	void toggleDelay();
};
