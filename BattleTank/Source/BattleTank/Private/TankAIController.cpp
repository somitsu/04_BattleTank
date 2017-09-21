// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank * ATankAIController::getAiControlledTank() const {return Cast<ATank>(GetPawn());}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto aiTank = getAiControlledTank();
	if (aiTank)	{UE_LOG(LogTemp, Warning, TEXT("ai controlled tank: %s"), *aiTank->GetName());}
	else { UE_LOG(LogTemp, Warning, TEXT("I aint here!!!")); }

}