// Fill out your copyright notice in the Description page of Project Settings.

#include "DrinkMachine.h"

ADrinkMachine::ADrinkMachine()
{
	DrinkMachine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DrinkMachine"));
	DrinkMachine->SetupAttachment(SceneComponent);
	DrinkMachineCover = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DrinkMachineCover"));
	DrinkMachineCover->SetupAttachment(DrinkMachine);

	DoorMoveDistance = 75.f;

}

void ADrinkMachine::BeginPlay()
{
	Super::BeginPlay();
	DoorClosePosition = DrinkMachineCover->GetComponentLocation();
	DoorOpenPosition = FVector(DoorClosePosition.X, DoorClosePosition.Y, DoorClosePosition.Z + DoorMoveDistance);
}

void ADrinkMachine::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting with the Drink Machine"));
	ToggleDoorRequest.Broadcast();

}




