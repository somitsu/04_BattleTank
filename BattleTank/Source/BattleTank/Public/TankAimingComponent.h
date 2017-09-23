// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

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

	void setBarrelReference(UTankBarrel * barrelToSet);
	void setTurretReference(UTankTurret * turretToSet);


protected:

public:	

	void aimAt(FVector hitLocation, float launchSpeed);

private:
	UTankBarrel * barrel = nullptr;
	UTankTurret * turret = nullptr;

	void moveBarrelTowards(FVector aimDirection);
	void moveTurretTowards(FVector aimDirection);
};
