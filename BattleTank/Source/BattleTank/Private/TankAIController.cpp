// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto controlledTank = GetPawn();
	auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(playerTank && controlledTank)) { return; }

	MoveToActor(playerTank, acceptanceRadius);
	auto aimingComponent = controlledTank->FindComponentByClass<UTankAimingComponent>();
	aimingComponent->aimAt(playerTank->GetActorLocation());

	if (aimingComponent->getFiringState() == EFiringStatus::locked)
	{
		aimingComponent->fire();
	}

}

