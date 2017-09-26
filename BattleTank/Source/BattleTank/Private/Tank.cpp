// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "projectile.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void ATank::setBarrelReference(UTankBarrel * barrelToSet)
{
	tankAimingComponent->setBarrelReference(barrelToSet);
	barrel = barrelToSet;
}

void ATank::setTurretReference(UTankTurret * turretToSet)
{
	tankAimingComponent->setTurretReference(turretToSet);
}

void ATank::setTrackReference(UTankTrack * rightTrackToSet, UTankTrack * leftTrackToSet)
{
	leftTrack = leftTrackToSet;
	rightTrack = rightTrackToSet;
	return;
}



void ATank::fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Firing!!!"));
	bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds;

	if (barrel && isReloaded)
	{
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

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	tankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::aimAt(FVector hitLocation)
{
	tankAimingComponent->aimAt(hitLocation, launchSpeed);

	return;
}
