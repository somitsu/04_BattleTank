// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "projectile.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::initialize(UTankTurret * turretToSet, UTankBarrel * barrelToSet)
{
	turret = turretToSet;
	barrel = barrelToSet;
}





void UTankAimingComponent::aimAt(FVector hitLocation)
{
	if (!ensure(barrel)) { return; }
	if (!ensure(turret)) { return; }
	
	FVector outLaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OUT outLaunchVelocity,
		startLocation,
		hitLocation,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{
		aimDirection = outLaunchVelocity.GetSafeNormal();
		// move barrel
		moveBarrelTowards(aimDirection);
		moveTurretTowards(aimDirection);
		// rotate x, z
	}

}

void UTankAimingComponent::moveBarrelTowards(FVector aimDirection)
{

	if (!ensure(barrel && turret)) { return; }
	auto barrelRotator = barrel->GetForwardVector().Rotation();
	auto aimAsRotator = aimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotator;

	barrel->elevate(deltaRotator.Pitch);
	return;
}

void UTankAimingComponent::moveTurretTowards(FVector aimDirection)
{
	auto turretRotator = turret->GetForwardVector().Rotation();
	auto aimAsRotator = aimDirection.Rotation();
	auto deltaRotator = aimAsRotator - turretRotator;
	if (deltaRotator.Yaw > 180) { deltaRotator.Yaw = -deltaRotator.Yaw; }
	turret->rotate(deltaRotator.Yaw);

	return;
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if ((FPlatformTime::Seconds() - lastFireTime) < reloadTimeInSeconds)
	{
		firingStatus = EFiringStatus::reloading;
	}
	else if (isBarrelMoving())
	{
		firingStatus = EFiringStatus::aiming;
	}
	else
	{
		firingStatus = EFiringStatus::locked;
	}
}

void UTankAimingComponent::BeginPlay()
{
	lastFireTime = FPlatformTime::Seconds();
}

bool UTankAimingComponent::isBarrelMoving()
{
	if (!ensure(barrel)) { return false; }
	auto barrelForward = barrel->GetForwardVector();
	return !barrelForward.Equals(aimDirection, 0.01f);
}

void UTankAimingComponent::fire()
{
	if (firingStatus != EFiringStatus::reloading)
	{
		if (!ensure(barrel)) { return; }
		if (!ensure(projectileBlueprint)) { return; }
		auto projectile = GetWorld()->SpawnActor<Aprojectile>(
			projectileBlueprint,
			barrel->GetSocketLocation("projectile"),
			barrel->GetSocketRotation("projectile")
			);
		projectile->launchProjectile(launchSpeed);
		lastFireTime = FPlatformTime::Seconds();
	}
	return;
}