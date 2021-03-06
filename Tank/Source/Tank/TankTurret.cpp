// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	float RotateChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->GetDeltaSeconds();
	float RawRotate = RelativeRotation.Yaw + RotateChange;
	SetRelativeRotation(FRotator(0, RawRotate, 0));
}


