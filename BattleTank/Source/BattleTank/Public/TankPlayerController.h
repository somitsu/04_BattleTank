// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	

	ATank * getControlledTank() const;
	void aimTowardsCrosshair();

private:

	bool getSightRayHitLocation(FVector &outHitLocation) const;
	bool getLookDirection(FVector2D screenLocation, FVector &outLookDirection) const;

	UPROPERTY(EditAnywhere)
	float crossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float crossHairYLocation = 0.333333f;

};
