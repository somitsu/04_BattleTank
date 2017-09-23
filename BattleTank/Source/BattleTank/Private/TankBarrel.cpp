// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"



void UTankBarrel::elevate(float relativeSpeed)
{
	
	auto elevationChange = FMath::Clamp<float>( relativeSpeed, -1, 1) * maxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto rawNewElevation = RelativeRotation.Pitch + elevationChange;
	auto elevation = FMath::Clamp<float>(rawNewElevation, minElevationDegrees, maxElevationDegrees);
	
	SetRelativeRotation(FRotator(elevation, 0, 0));

}
