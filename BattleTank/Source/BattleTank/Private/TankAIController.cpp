// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto controlledTank = Cast<ATank>(GetPawn());
	auto playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (playerTank)
	{

		MoveToActor(playerTank, acceptanceRadius);

		controlledTank->aimAt(playerTank->GetActorLocation());
		controlledTank->fire();

	}

}




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	

}