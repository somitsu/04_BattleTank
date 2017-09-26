// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

/////////////////////////////////// Methods ///////////////////////////////////
public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void initialize(UTankTrack * leftTrackToSet, UTankTrack * rightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void intendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void intendTurnRight(float Throw);

private:

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;


/////////////////////////////////// Variables ///////////////////////////////////
private:
	UTankTrack * leftTrack = nullptr;
	UTankTrack * rightTrack = nullptr;



};
