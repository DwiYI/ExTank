// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"


#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) return;
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntentMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntentMoveTurn(float Throw)
{
	
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();

	float ThrowForward = FVector::DotProduct(TankForward, AiForwardIntention);

	float ThrowTurn = FVector::CrossProduct(TankForward, AiForwardIntention).Z;
	UE_LOG(LogTemp, Warning, TEXT(" z turn %f at %f"), ThrowForward, ThrowTurn);
	IntentMoveForward(ThrowForward);
	IntentMoveTurn(ThrowTurn);
}
