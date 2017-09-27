// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
/////////////////////////////////// Methods ///////////////////////////////////	

public:
	void elevate(float relativeSpeed);

protected:

private:

/////////////////////////////////// Variables ///////////////////////////////////
public:

protected:

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float maxDegreePerSecond = 5.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float minElevationDegrees = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float maxElevationDegrees = 40.0f;

};
