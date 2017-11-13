// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTankAimComponent::SetBarrelReferences(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimComponent::SetTurretReferences(UTankTurret * TankToSet)
{
	if (!TankToSet) { return; }
	Turret = TankToSet;
}


void UTankAimComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	//UE_LOG(LogTemp, Warning, TEXT("Start Location : %s"), *(StartLocation.ToString()));
	//UE_LOG(LogTemp, Warning, TEXT("Hit Location : %s"), *(HitLocation.ToString()));

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
		FString name = GetOwner()->GetName();
		MoveBarrelToward(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("Get Aim Solution"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("No Aim Solution"));
	}
	
}

void UTankAimComponent::MoveBarrelToward(FVector AimDirection)
{
	FRotator AimRotator = AimDirection.Rotation();
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator DeltaRotator = AimRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

