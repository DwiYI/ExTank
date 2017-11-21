// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTank.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class TANK_API AMyTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTank();


	UPROPERTY(EditDefaultsOnly, Category = Setup)
	int StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = Health)
	int CurrentHealth;

	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealthPercentage() const;

	FTankDelegate OnDeath;

	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

};
