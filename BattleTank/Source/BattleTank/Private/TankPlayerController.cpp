// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"
#define OUT


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	return;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	aimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Ticking!!!"));


	return;
}


ATank * ATankPlayerController::getControlledTank() const { return Cast<ATank>(GetPawn()); }

void ATankPlayerController::aimTowardsCrosshair()
{
	if (!getControlledTank()) { return; }
	
	FVector hitLocation; //Out parameter
	if (getSightRayHitLocation(OUT hitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("debug: %s"), *hitLocation.ToString())
		getControlledTank()->aimAt(hitLocation);
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

		getLookVectorHitLocation(lookDirection, outHitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("hit location: %s"), *outHitLocation.ToString())
	}

	return true;
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