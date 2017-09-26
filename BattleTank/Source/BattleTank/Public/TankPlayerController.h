// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank * getControlledTank() const;


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	

	void aimTowardsCrosshair();

private:

	bool getSightRayHitLocation(FVector &outHitLocation) const;
	bool getLookDirection(FVector2D screenLocation, FVector &outLookDirection) const;
	bool getLookVectorHitLocation(FVector lookDirection, FVector &outHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float crossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float crossHairYLocation = 0.333333f;

	UPROPERTY(EditDefaultsOnly)
	float lineTraceRange = 1000000.0f;


};
