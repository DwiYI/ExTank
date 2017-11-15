// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTank.generated.h"

class UTankAimComponent;
class UTankMovementComponent;
class AProjectile;
class UTankTrack;

UCLASS()
class TANK_API AMyTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTank();

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
