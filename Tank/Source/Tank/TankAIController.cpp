// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	FString result = "";

	if (GetPlayerTank())
	{
		result = GetPlayerTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Begin Play AI : Target Player : %s"), *result);
	}

}

AMyTank* ATankAIController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}

AMyTank* ATankAIController::GetPlayerTank() const
{
    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<AMyTank>(PlayerPawn);
}


