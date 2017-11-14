// Fill out your copyright notice in the Description page of Project Settings.
#include "MyTank.h"
#include "TankAimComponent.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
AMyTank::AMyTank()
{
	
}

void AMyTank::AimAt(FVector aim)
{
	TankAimComponent->AimAt(aim, LaunchSpeed);
}


void AMyTank::InitializeTankAim(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet, UTankAimComponent * TankAimComponentToSet)
{
	if (!BarrelToSet || !TurretToSet || !TankAimComponentToSet) { return; }
	TankAimComponent = TankAimComponentToSet;
	TankAimComponent->Initialize(BarrelToSet, TurretToSet);
	Barrel = BarrelToSet;
}

void AMyTank::InitializeTankMove(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet, UTankMovementComponent* TankMovementComponentToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet || !TankMovementComponentToSet) { return; }
	TankMovementComponent = TankMovementComponentToSet;
	TankMovementComponent->Initialize(LeftTrackToSet, RightTrackToSet);
}

void AMyTank::Fire()
{
	bool IsReloaded = (GetWorld()->GetTimeSeconds() - FireRatePerSecond) > LastFireTime;

	if (Barrel && IsReloaded)
	{
		FVector LocationSpawn = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator Rotation = Barrel->GetSocketRotation(FName("Projectile"));
		AProjectile *ProjectileSpawn = GetWorld()->SpawnActor<AProjectile>(Projectile, LocationSpawn, Rotation);
		ProjectileSpawn->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}

}


// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

