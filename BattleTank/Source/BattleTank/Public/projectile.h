// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "projectile.generated.h"


class UProjectileMovementComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class URadialForceComponent;

UCLASS()
class BATTLETANK_API Aprojectile : public AActor
{
	GENERATED_BODY()

/////////////////////////////////// Methods ///////////////////////////////////
public:	
	// Sets default values for this actor's properties
	Aprojectile();

	void launchProjectile(float speed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);


/////////////////////////////////// Variables ///////////////////////////////////
public:

protected:

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent * collisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent * launchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent * impactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent * explosionForce = nullptr;

	UProjectileMovementComponent * projectileMovement = nullptr;
	
};
