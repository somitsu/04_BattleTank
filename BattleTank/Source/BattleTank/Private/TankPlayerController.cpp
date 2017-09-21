// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank * ATankPlayerController::getControlledTank() const { return Cast<ATank>(GetPawn()); }

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto controlledTank = getControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("playerController begin play"));

	if (controlledTank)	{ UE_LOG(LogTemp, Warning, TEXT("controlled tank: %s"), *controlledTank->GetName()); }
	else { UE_LOG(LogTemp, Warning, TEXT("grabbed NADA!!")); }

}
