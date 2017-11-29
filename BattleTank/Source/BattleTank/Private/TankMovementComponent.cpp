// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTracks.h"

void UTankMovementComponent::Initialise(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet)
{
	LeftTracks = LeftTrackToSet;
	RightTracks = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTracks || !RightTracks) { return; }

	LeftTracks->SetThrottle(Throw);
	RightTracks->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTracks || !RightTracks) { return; }

	LeftTracks->SetThrottle(Throw);
	RightTracks->SetThrottle(0);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (!LeftTracks || !RightTracks) { return; }

	LeftTracks->SetThrottle(0);
	RightTracks->SetThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto ForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(ForwardDirection, ForwardIntention);

	IntendMoveForward(ForwardThrow);

	auto TurnThrow = FVector::CrossProduct(ForwardDirection, ForwardIntention);

	IntendTurnRight(TurnThrow.Z);

	UE_LOG(LogTemp, Warning, TEXT("Throw: %f"), ForwardThrow);
}
