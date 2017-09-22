// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::setBarrelReference(UTankBarrel * barrelToSet)
{
	barrel = barrelToSet;
}



void UTankAimingComponent::aimAt(FVector hitLocation, float launchSpeed)
{
	if (!barrel) { return; }
	
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
		auto aimDirection = outLaunchVelocity.GetSafeNormal();
		// move barrel
		moveBarrelTowards(aimDirection);
		// rotate x, z
		UE_LOG(LogTemp, Warning, TEXT("%f: aim solution found"), GetWorld()->GetTimeSeconds());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f: aim solution not found"), GetWorld()->GetTimeSeconds());
	}
}

void UTankAimingComponent::moveBarrelTowards(FVector aimDirection)
{
	auto barrelRotator = barrel->GetForwardVector().Rotation();
	auto aimAsRotator = aimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotator;

	UE_LOG(LogTemp, Warning, TEXT("aimsAsRotator: %s"), *aimAsRotator.ToString());

	barrel->elevate(5);

	return;
}
