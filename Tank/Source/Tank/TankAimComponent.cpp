// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


void UTankAimComponent::Initialize(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	if (!BarrelToSet || !TurretToSet) { return; }
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}


void UTankAimComponent::AimAt(FVector HitLocation)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	bool bAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	
	if(bAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		AimDirectionOwner = AimDirection;
		MoveBarrelToward(AimDirection);
	}
	
}

void UTankAimComponent::Fire()
{
	if (Status != EFiringStatus::Reloading)
	{
		if (!ensure(Barrel && Projectile)) return;
		FVector LocationSpawn = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator Rotation = Barrel->GetSocketRotation(FName("Projectile"));
		AProjectile *ProjectileSpawn = GetWorld()->SpawnActor<AProjectile>(Projectile, LocationSpawn, Rotation);
		ProjectileSpawn->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}

void UTankAimComponent::BeginPlay()
{
	LastFireTime = GetWorld()->GetTimeSeconds();
}

void UTankAimComponent::MoveBarrelToward(FVector AimDirection)
{
	FRotator AimRotator = AimDirection.Rotation();
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator DeltaRotator = AimRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

bool UTankAimComponent::IsBarrelMoving()
{
	return  !(Barrel->GetForwardVector()).Equals(AimDirectionOwner, 0.1f);
}

void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if ((GetWorld()->GetTimeSeconds() - LastFireTime ) < FireRatePerSecond)
	{
		Status = EFiringStatus::Reloading;
	}
	else if (IsBarrelMoving())
	{
		Status = EFiringStatus::Aiming;
	}
	else
	{
		Status = EFiringStatus::Locked;
	}
}

