// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UTankTrack();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetThrottle(float speed);

	void DriveTrack();
	
	UPROPERTY(EditDefaultsOnly, Category = Force)
	float MaxForce = 400000.0f;


	void ApplySideForce();

	virtual void BeginPlay() override;
private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector  NormalImpulse, const FHitResult& Hit);
	float CurrentThrottle = 0;
};
