// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"



void UTankMovementComponent::initialize(UTankTrack * leftTrackToSet, UTankTrack * rightTrackToSet)
{
	leftTrack = leftTrackToSet;
	rightTrack = rightTrackToSet;

}

void UTankMovementComponent::intendMoveForward(float Throw)
{
	if (!leftTrack || !rightTrack) { return; }
	leftTrack->setThrottle(Throw);
	rightTrack->setThrottle(Throw);
	
}

void UTankMovementComponent::intendTurnRight(float Throw)
{
	if (!leftTrack || !rightTrack) { return; }
	leftTrack->setThrottle(Throw);
	rightTrack->setThrottle(-Throw);
}