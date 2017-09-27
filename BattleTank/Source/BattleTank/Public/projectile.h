// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "projectile.generated.h"


class UProjectileMovementComponent;

UCLASS()
class BATTLETANK_API Aprojectile : public AActor
{
	GENERATED_BODY()

/////////////////////////////////// Methods ///////////////////////////////////
public:	
	// Sets default values for this actor's properties
	Aprojectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void launchProjectile(float speed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

/////////////////////////////////// Variables ///////////////////////////////////
public:

protected:

private:
	UProjectileMovementComponent * projectileMovement = nullptr;
	
};
