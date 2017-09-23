// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void aimAt( FVector hitLocation );

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setBarrelReference(UTankBarrel* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setTurretReference(UTankTurret* turretToSet);


protected:
	UTankAimingComponent* tankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float launchSpeed = 4000.0f; // cm/s

	
	
};
