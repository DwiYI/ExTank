// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"


UENUM()
enum class EFiringStatus : uint8
{
	Locked,
	Aiming,
	Reloading,
	NOAMMO
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);
	
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000.0f;

	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<AProjectile> Projectile;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	EFiringStatus GetFiringStatus() const;

	UFUNCTION(BlueprintCallable, Category = Ammo)
	int GetAmmo() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = Color)
	EFiringStatus Status = EFiringStatus::Reloading;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelToward(FVector AimDirection);
	float FireRatePerSecond = 3;
	float LastFireTime = 0;
	FVector AimDirectionOwner;
	bool IsBarrelMoving();

	UPROPERTY(EditAnywhere, Category = Color)
	int Ammo = 3;

	bool IsAmmoEmpty();

};
