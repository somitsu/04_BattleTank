// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"
#define OUT


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(aimingComponent)) { return;	}
	foundAimingComponent(aimingComponent);

	return;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	aimTowardsCrosshair();


	return;
}



void ATankPlayerController::aimTowardsCrosshair()
{
	if (!GetPawn()) { return; }
	if (!ensure(aimingComponent)) { return; }
	
	FVector hitLocation; //Out parameter

	bool bGotHitLocation = getSightRayHitLocation(OUT hitLocation);
	if (bGotHitLocation)
	{
		aimingComponent->aimAt(hitLocation);
	}
	return;
}

bool ATankPlayerController::getSightRayHitLocation(FVector &outHitLocation) const
{
	int32 viewportSizeX, viewportSizeY;
	FVector2D screenLocation;
	FVector lookDirection;

	GetViewportSize(OUT viewportSizeX, OUT viewportSizeY);

	screenLocation = FVector2D(viewportSizeX * crossHairXLocation, viewportSizeY * crossHairYLocation);

	if (getLookDirection(screenLocation, OUT lookDirection))
	{
		return getLookVectorHitLocation(lookDirection, outHitLocation);
	}

	return false;
}


bool ATankPlayerController::getLookDirection(FVector2D screenLocation, FVector &outLookDirection) const
{
	FVector cameraWorldLocation;
	return (DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, outLookDirection));
}

bool ATankPlayerController::getLookVectorHitLocation(FVector lookDirection, FVector &outHitLocation) const
{
	FHitResult lineTraceHit;
	FVector startLocation = PlayerCameraManager->GetCameraLocation();
	FVector endLocation = startLocation + lookDirection*lineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(
			OUT lineTraceHit,
			startLocation,
			endLocation,
			ECollisionChannel::ECC_Visibility
		))
	{ 
		outHitLocation = lineTraceHit.Location;
		return true; 
	}
	else 
	{ 
		outHitLocation = FVector(0.0f);
		return false; 
	}



}

void ATankPlayerController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto possessedTank = Cast<ATank>(InPawn);
		if (!ensure(possessedTank)) { return; }
		possessedTank->onDeath.AddUniqueDynamic(this, &ATankPlayerController::onPossessedTankDeath);

	}


}

void ATankPlayerController::onPossessedTankDeath()
{
	StartSpectatingOnly();

}
