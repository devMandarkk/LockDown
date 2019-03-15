// Fill out your copyright notice in the Description page of Project Settings.

#include "FoodMachine.h"

AFoodMachine::AFoodMachine() {
	FoodMachine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FoodMachine"));
	FoodMachine->SetupAttachment(SceneComponent);

	FoodMachineCover = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FoodMachineCover"));
	FoodMachineCover->SetupAttachment(FoodMachine);

	//DoorOpenPosition = CreateDefaultSubobject<USceneComponent>(TEXT("DoorOpenPosition"));
	//DoorOpenPosition->SetupAttachment(FoodMachineCover);

	//DoorClosePosition = CreateDefaultSubobject<USceneComponent>(TEXT("DoorClosePosition"));
	//DoorClosePosition->SetupAttachment(FoodMachineCover);

	DoorMoveDistance = 100.f;
}

void AFoodMachine::BeginPlay(){
	Super::BeginPlay();
	DoorClosePosition = FoodMachineCover->GetComponentLocation();
	DoorOpenPosition = FVector(DoorClosePosition.X, DoorClosePosition.Y, DoorClosePosition.Z + DoorMoveDistance);
	UE_LOG(LogTemp, Warning, TEXT("Food machine close cover position is %s"), *DoorClosePosition.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Food machine open cover position is %s"), *DoorOpenPosition.ToString());

}


void AFoodMachine::OnInteract(){
	//UE_LOG(LogTemp, Warning, TEXT("Interacting with the Food Machine"));
	//fire an event and handle the movement in BPs
	ToggleDoorRequest.Broadcast();
}

