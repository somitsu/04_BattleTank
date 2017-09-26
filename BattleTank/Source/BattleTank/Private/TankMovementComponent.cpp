// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::initialize(UTankTrack * leftTrackToSet, UTankTrack * rightTrackToSet)
{
	if (!leftTrackToSet || !rightTrackToSet) { return; }
	leftTrack = leftTrackToSet;
	rightTrack = rightTrackToSet;

}

void UTankMovementComponent::intendMoveForward(float Throw)
{
	
	UE_LOG(LogTemp, Warning, TEXT("intend move forward Throw: %f"), Throw);

	leftTrack->setThrottle(Throw);
	rightTrack->setThrottle(Throw);
	
}

