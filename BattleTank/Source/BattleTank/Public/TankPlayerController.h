// Copyright AWTC Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * Responsible for helping the player aim
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

/////////////////////////////////// Methods ///////////////////////////////////	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void aimTowardsCrosshair();

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void foundAimingComponent(UTankAimingComponent * aimingCompRef);

private:
	bool getSightRayHitLocation(FVector &outHitLocation) const;
	bool getLookDirection(FVector2D screenLocation, FVector &outLookDirection) const;
	bool getLookVectorHitLocation(FVector lookDirection, FVector &outHitLocation) const;
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void onPossessedTankDeath();

/////////////////////////////////// Variables ///////////////////////////////////
public:

protected:

private:
	UPROPERTY(EditDefaultsOnly)
	float crossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float crossHairYLocation = 0.333333f;

	UPROPERTY(EditDefaultsOnly)
	float lineTraceRange = 1000000.0f;

	UTankAimingComponent * aimingComponent = nullptr;
};
