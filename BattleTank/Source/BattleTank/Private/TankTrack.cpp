// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}



void UTankTrack::applySidewaysForce()
{
	auto deltaTime = GetWorld()->GetDeltaSeconds();
	float slippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	auto correctionAcceleration = -slippageSpeed / deltaTime * GetRightVector();
	auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto correctionForce = (tankRoot->GetMass() * correctionAcceleration) / 2;
	tankRoot->AddForce(correctionForce);
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Im hit!!!"));
	driveTrack();
	applySidewaysForce();
	currentThrottle = 0.0f;
}

void UTankTrack::setThrottle(float throttle)
{
	currentThrottle = FMath::Clamp<float>(currentThrottle + throttle, -1.0, 1.0);	
}

void UTankTrack::driveTrack()
{
	auto forceApplied = GetForwardVector()* currentThrottle *trackMaxDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}