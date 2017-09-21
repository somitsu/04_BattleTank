// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#define OUT


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto controlledTank = getControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("playerController begin play"));

	if (controlledTank)	{ UE_LOG(LogTemp, Warning, TEXT("controlled tank: %s"), *controlledTank->GetName()); }
	else { UE_LOG(LogTemp, Warning, TEXT("grabbed NADA!!")); }

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
		UE_LOG(LogTemp, Warning, TEXT("%s"), *hitLocation.ToString());
	}



	return;
}

bool ATankPlayerController::getSightRayHitLocation(FVector &outHitLocation) const
{
	//if (!GetWorld()->GetFirstPlayerController())
	//{
	//	return false;
	//}
	//
	//FVector playerViewLocation;
	//FRotator playerViewRotator;
	//
	//GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
	//	OUT playerViewLocation,
	//	OUT playerViewRotator
	//);

	//return true;

	outHitLocation = FVector(1.0f);
	return true;
}
