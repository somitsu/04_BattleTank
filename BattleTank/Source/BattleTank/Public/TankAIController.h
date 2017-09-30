// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

/////////////////////////////////// Methods ///////////////////////////////////
public:

protected:

private:
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void onPossessedTankDeath();

	
/////////////////////////////////// Variables ///////////////////////////////////
public:

protected:

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float acceptanceRadius = 8000.0f;
	
};
