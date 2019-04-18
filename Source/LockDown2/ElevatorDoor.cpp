// Fill out your copyright notice in the Description page of Project Settings.

#include "ElevatorDoor.h"

// Sets default values
AElevatorDoor::AElevatorDoor()
{
	DoorRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorRight"));
	DoorRight->SetupAttachment(SceneComponent);
	DoorLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLeft"));
	DoorLeft->SetupAttachment(SceneComponent);

	IsOpen = NULL;
}

void AElevatorDoor::ToggleDoor()
{
	Super::ToggleDoor();

	UE_LOG(LogTemp, Warning, TEXT("Time to toggle elevator room door"));
	ToggleDoorRequest.Broadcast();
	IsOpen = !IsOpen;
}

// Called when the game starts or when spawned
void AElevatorDoor::BeginPlay()
{
	Super::BeginPlay();
	
}


