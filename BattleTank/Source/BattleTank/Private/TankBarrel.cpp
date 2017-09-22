// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"



void UTankBarrel::elevate(float degreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("barrel->elevate() called at speed %f"), degreesPerSecond);
}
