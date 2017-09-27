// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	reloading,
	aiming,
	locked
};


// forward declaration
class UTankBarrel;
class UTankTurret;

// holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void initialize(UTankTurret * turretToSet, UTankBarrel * barrelToSet);


	//void setBarrelReference(UTankBarrel * barrelToSet);
	//void setTurretReference(UTankTurret * turretToSet);


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus firingStatus = EFiringStatus::aiming;


public:	

	void aimAt(FVector hitLocation);

private:
	UTankBarrel * barrel = nullptr;
	UTankTurret * turret = nullptr;

	void moveBarrelTowards(FVector aimDirection);
	void moveTurretTowards(FVector aimDirection);

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float launchSpeed = 4000.0f; // cm/s

};
