// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Engine/World.h"
#include "MyTank.h"


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

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
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


