// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTank.generated.h"

class UTankAimComponent;
class UTankMovementComponent;
class AProjectile;
class UTankTrack;

UCLASS()
class TANK_API AMyTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTank();
	void AimAt(FVector aim);

	// Set Barrel And Turret And Aim Component
	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitializeTankAim(UTankBarrel* BarelToSet, UTankTurret* TurretToSet, UTankAimComponent* TankAimComponentToSet);
	
	// Set Track And Move Component
	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitializeTankMove(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet, UTankMovementComponent* TankMovementComponentToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimComponent* TankAimComponent = nullptr;

	UTankMovementComponent* TankMovementComponent = nullptr;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000.0f;

	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<AProjectile> Projectile;

private:
	UTankBarrel* Barrel = nullptr;
	float FireRatePerSecond = 3;
	float LastFireTime = 0;
};
