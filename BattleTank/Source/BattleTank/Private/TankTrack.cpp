// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float slippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	auto correctionAcceleration = -slippageSpeed / DeltaTime * GetRightVector();
	auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto correctionForce = (tankRoot->GetMass() * correctionAcceleration) / 2;
	tankRoot->AddForce(correctionForce);
	//UE_LOG(LogTemp, Warning, TEXT("slippage: %f"), slippageSpeed);

}



void UTankTrack::setThrottle(float throttle)
{
	auto forceApplied = GetForwardVector()*throttle *trackMaxDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}

