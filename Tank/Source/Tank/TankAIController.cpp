// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimComponent.h"
#include "MyTank.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UTankAimComponent* ControlledTankAim = GetPawn()->FindComponentByClass<UTankAimComponent>();
	APawn* PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		ControlledTankAim->AimAt(PlayerTank->GetActorLocation());
		if (ControlledTankAim->GetFiringStatus() == EFiringStatus::Locked)
		{
			ControlledTankAim->Fire();
		}
	}
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto TankPosses = Cast<AMyTank>(InPawn);
		if (!TankPosses) return;
		TankPosses->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}

void ATankAIController::OnTankDeath()
{
	if (!GetPawn()) return;
	GetPawn()->DetachFromControllerPendingDestroy();

}
