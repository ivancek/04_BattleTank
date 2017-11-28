// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTracks.h"

void UTankMovementComponent::Initialise(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTracks = LeftTrackToSet;
	RightTracks = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTracks || !RightTracks) { return; }

	LeftTracks->SetThrottle(Throw);
	RightTracks->SetThrottle(Throw);
}