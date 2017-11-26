// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"
/*
*/
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }
		
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find crosshair position in screen
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLoc = FVector2D(
		ViewportSizeX * CrossHairXLocation, 
		ViewportSizeY * CrossHairYLocation
	);

	FVector LookDirection;
	if (GetLookDirection(ScreenLoc, LookDirection))
	{
		// Linetrace
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		return true;
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraLoc;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLoc, LookDirection);
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	auto LineTraceStart = PlayerCameraManager->GetCameraLocation();
	FVector LineTraceEnd = LineTraceStart + (LookDirection * LineTraceRange);

	/// Raycast out to reach distance
	FHitResult HitResult;
	
	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		LineTraceStart,
		LineTraceEnd,
		ECC_Visibility,
		FCollisionQueryParams(FName(TEXT("")), false, GetOwner())
	))
	{
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false;
}
