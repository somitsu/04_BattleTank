// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"


void UTankTurret::rotate(float relativeSpeed)
{
	auto rotationChange = FMath::Clamp<float>(relativeSpeed, -1, 1) * maxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto rotation = RelativeRotation.Yaw + rotationChange;

	SetRelativeRotation(FRotator(0, rotation, 0));
}

