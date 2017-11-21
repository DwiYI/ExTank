// Fill out your copyright notice in the Description page of Project Settings.
#include "MyTank.h"


// Sets default values
AMyTank::AMyTank()
{
	PrimaryActorTick.bCanEverTick = false;
}


float AMyTank::GetHealthPercentage() const
{
	return (float)CurrentHealth / (float) StartingHealth ;
}

void AMyTank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float AMyTank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{

	int32 DamagePoint = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp<int>(DamagePoint, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;

	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}

	return DamageAmount;
}

