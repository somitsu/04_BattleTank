// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank * ATankAIController::getControlledTank() const {return Cast<ATank>(GetPawn());}

ATank * ATankAIController::getPlayerTank() const { return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); }

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto aiTank = getControlledTank();
	if (aiTank)	{UE_LOG(LogTemp, Warning, TEXT("ai controlled tank: %s"), *aiTank->GetName());}
	else { UE_LOG(LogTemp, Warning, TEXT("I aint here!!!")); }

	auto playerTank = getPlayerTank();
	if (playerTank) { UE_LOG(LogTemp, Warning, TEXT("player controlled tank found by AI: %s"), *playerTank->GetName()); }
	else { UE_LOG(LogTemp, Warning, TEXT("I aint here!!!")); }

	

}