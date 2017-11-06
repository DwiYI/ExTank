// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




AMyTank* ATankPlayerController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FString result = "";

	if (GetControlledTank())
	{
		result = GetControlledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Begin Play : %s"), *result);
	}

	
}
