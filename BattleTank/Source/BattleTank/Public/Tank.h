// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class UTankTrack;
class UTankMovementComponent;
class Aprojectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void setBarrelReference(UTankBarrel* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void setTurretReference(UTankTurret* turretToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void setTrackReference(UTankTrack * rightTrackToSet, UTankTrack * leftTrackToSet);


	UFUNCTION(BlueprintCallable)
	void fire();

	void aimAt(FVector hitLocation);

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* tankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* tankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float launchSpeed = 4000.0f; // cm/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float reloadTimeInSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<Aprojectile> projectileBlueprint;

	UTankBarrel * barrel = nullptr;

	UTankTrack * leftTrack = nullptr;
	UTankTrack * rightTrack = nullptr;



	double lastFireTime = 0.0;

};
