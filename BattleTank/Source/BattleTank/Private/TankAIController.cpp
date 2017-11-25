// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (ATank* Tank = GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller: %s"), *Tank->GetName());
	}

	if (ATank* PlayerTank = GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller: Found player tank ( %s )"), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
