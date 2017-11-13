// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();
	void SetBarrelReferences(UTankBarrel* BarrelToSet);
	void SetTurretReferences(UTankTurret* TankToSet);
	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelToward(FVector AimDirection);
	
};