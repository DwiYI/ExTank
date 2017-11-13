// Fill out your copyright notice in the Description page of Project Settings.
#include "MyTank.h"
#include "TankAimComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
AMyTank::AMyTank()
{
	TankAimComponent = CreateDefaultSubobject<UTankAimComponent>(FName("Aim Component"));
}

void AMyTank::AimAt(FVector aim)
{
	TankAimComponent->AimAt(aim, LaunchSpeed);
}

void AMyTank::SetBarrelReferences(UTankBarrel * BarrelToSet)
{
	TankAimComponent->SetBarrelReferences(BarrelToSet);
	Barrel = BarrelToSet;
}

void AMyTank::SetTurretReferences(UTankTurret * TurretToSet)
{
	TankAimComponent->SetTurretReferences(TurretToSet);
}

void AMyTank::Fire()
{
	if (!Barrel) return;
	FVector LocationSpawn = Barrel->GetSocketLocation(FName("Projectile"));
	FRotator Rotation = Barrel->GetSocketRotation(FName("Projectile"));
	AProjectile *ProjectileSpawn = GetWorld()->SpawnActor<AProjectile>(Projectile, LocationSpawn, Rotation);
	ProjectileSpawn->LaunchProjectile(LaunchSpeed);

}


// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

