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
	if (!ensure(leftTrack && rightTrack)) { return; }
	leftTrack->setThrottle(Throw);
	rightTrack->setThrottle(Throw);
	
}

void UTankMovementComponent::intendTurnRight(float Throw)
{
	if (!ensure(leftTrack && rightTrack)) { return; }
	leftTrack->setThrottle(Throw);
	rightTrack->setThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	FVector aiForwardIntention = MoveVelocity.GetSafeNormal();
	FVector tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	float forwardThrow = FVector::DotProduct(aiForwardIntention, tankForward);
	float rotateThrow = FVector::CrossProduct(tankForward, aiForwardIntention).Z;

	intendTurnRight(rotateThrow);
	intendMoveForward(forwardThrow);


}
