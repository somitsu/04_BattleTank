// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "projectile.h"
#include "TankBarrel.h"
#include "TankTrack.h"


void ATank::setBarrelReference(UTankBarrel * barrelToSet)
{
	//tankAimingComponent->setBarrelReference(barrelToSet);
	barrel = barrelToSet;
}





void ATank::fire()
{

	//UE_LOG(LogTemp, Warning, TEXT("Firing!!!"));

	if (!ensure(barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds;

	if (isReloaded)
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
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: C++ Constructor"), *GetName());

	//tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: C++ BeginPlay"), *GetName());



}



