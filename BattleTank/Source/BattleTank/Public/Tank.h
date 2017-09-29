// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class AController;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

/////////////////////////////////// Methods ///////////////////////////////////
public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "Health")
	float getHealthPercent() const;

protected:
	

private:
	// Sets default values for this pawn's properties
	ATank();

/////////////////////////////////// Variables ///////////////////////////////////
public:

protected:

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 startingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 currentHealth = startingHealth;

};
