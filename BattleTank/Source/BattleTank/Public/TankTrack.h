// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
/////////////////////////////////// Methods ///////////////////////////////////	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void setThrottle(float throttle);
protected:

private:
	UTankTrack();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


/////////////////////////////////// Variables ///////////////////////////////////
public:
	UPROPERTY(EditDefaultsOnly)
	float trackMaxDrivingForce = 20000000.0f; //N

protected:

private:


};
