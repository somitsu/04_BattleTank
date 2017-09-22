// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::setBarrelReference(UStaticMeshComponent * barrelToSet)
{
	barrel = barrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::aimAt(FVector hitLocation, float launchSpeed)
{
	if (!barrel) { return; }
	
	FVector outLaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("projectile"));
	
	if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			OUT outLaunchVelocity,
			startLocation,
			hitLocation,
			launchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
			)
		)
	{
		auto aimDirection = outLaunchVelocity.GetSafeNormal();
		auto tankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("tank %s aiming at %s"), *tankName, *aimDirection.ToString());
	}

}

