// Fill out your copyright notice in the Description page of Project Settings.
#include "MyTank.h"
#include "TankAimComponent.h"



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
}

void AMyTank::SetTurretReferences(UTankTurret * TurretToSet)
{
	TankAimComponent->SetTurretReferences(TurretToSet);
}

void AMyTank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire !!"));
}


// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

