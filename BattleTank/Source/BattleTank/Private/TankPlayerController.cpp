// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

/*
*/
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ATank* Tank = GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller:  %s"), *Tank->GetName());
	}
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
