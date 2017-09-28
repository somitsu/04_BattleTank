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
	locked,
	outOfAmmo
};




// forward declaration
class UTankBarrel;
class UTankTurret;
class Aprojectile;

// holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()



/////////////////////////////////// Methods ///////////////////////////////////
public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void initialize(UTankTurret * turretToSet, UTankBarrel * barrelToSet);

	void aimAt(FVector hitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void fire();

	EFiringStatus getFiringState() const;


	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 getAmmoCount() const;

protected:

private:
	void moveBarrelTowards(FVector aimDirection);
	void moveTurretTowards(FVector aimDirection);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	virtual void BeginPlay() override;

	bool isBarrelMoving();

/////////////////////////////////// Variables ///////////////////////////////////
public:

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus firingStatus = EFiringStatus::reloading;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 ammoCount = 10;

private:

	UTankBarrel * barrel = nullptr;
	UTankTurret * turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<Aprojectile> projectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float launchSpeed = 4000.0f; // cm/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float reloadTimeInSeconds = 3.0f;

	double lastFireTime = 0.0;

	FVector aimDirection = FVector(0.0f);



};
