// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT(" barrel elevate :  %f"), RelativeSpeed);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	float ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->GetDeltaSeconds();
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float ElevationClamp = FMath::ClampAngle(RawNewElevation, MinElevationDegree, MaxElevationDegree);
	SetRelativeRotation(FRotator(ElevationClamp, 0, 0));
}


