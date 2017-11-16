// Fill out your copyright notice in the Description page of Project Settings.
#include "MyTank.h"


// Sets default values
AMyTank::AMyTank()
{
	PrimaryActorTick.bCanEverTick = false;
}


// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

