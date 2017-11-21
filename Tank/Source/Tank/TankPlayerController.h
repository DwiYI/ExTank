// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class AMyTank;
class UTankAimComponent;
/**
 * 
 */
UCLASS()
class TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	


protected:
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimComponent* AimCompRef);
public:

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .333333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000.0f;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnTankDeath();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const;

private:
	UTankAimComponent* TankAimComponent = nullptr;
};
