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

public:

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	//UPROPERTY(EditDefaultsOnly, Category = AI setup)
	float acceptanceRadius = 3000.0f;
	
};
