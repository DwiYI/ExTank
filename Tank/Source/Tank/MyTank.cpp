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
	TankAimComponent = FindComponentByClass<UTankAimComponent>();
}

void AMyTank::AimAt(FVector aim)
{
	if (!TankAimComponent) return;
	TankAimComponent->AimAt(aim, LaunchSpeed);
}


void AMyTank::Fire()
{
	//if (!ensure(Barrel)) return;
	//bool IsReloaded = (GetWorld()->GetTimeSeconds() - FireRatePerSecond) > LastFireTime;

	//if (IsReloaded)
	//{
	//	FVector LocationSpawn = Barrel->GetSocketLocation(FName("Projectile"));
	//	FRotator Rotation = Barrel->GetSocketRotation(FName("Projectile"));
	//	AProjectile *ProjectileSpawn = GetWorld()->SpawnActor<AProjectile>(Projectile, LocationSpawn, Rotation);
	//	ProjectileSpawn->LaunchProjectile(LaunchSpeed);
	//	LastFireTime = GetWorld()->GetTimeSeconds();
	//}
	return;
}


// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

