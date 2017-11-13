// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), HideCategories = ("Collision"))
class TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Elevate(float RelativeSpeed);
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSecond = 20.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegree = 0.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegree = 40.0f;
};
