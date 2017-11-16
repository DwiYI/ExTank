// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimComponent.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UTankAimComponent* ControlledTankAim = GetPawn()->FindComponentByClass<UTankAimComponent>();
	APawn* PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		ControlledTankAim->AimAt(PlayerTank->GetActorLocation());
		ControlledTankAim->Fire();
	}
}

