// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()



public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = ArtificialMovement)
	float AcceptanceRadius = 3000;
};
