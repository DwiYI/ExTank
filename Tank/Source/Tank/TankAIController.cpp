// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Engine/World.h"
#include "MyTank.h"



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AMyTank* ControlledTank = Cast<AMyTank>(GetPawn());
	AMyTank* PlayerTank = Cast<AMyTank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
}

