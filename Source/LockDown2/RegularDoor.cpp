// Fill out your copyright notice in the Description page of Project Settings.

#include "RegularDoor.h"

ARegularDoor::ARegularDoor() {
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	mesh->SetupAttachment(boxTrigger);

	//StartPosition = CreateDefaultSubobject<USceneComponent>(TEXT("StartPosition"));
	//StartPosition->SetupAttachment(boxTrigger);
	//EndPosition = CreateDefaultSubobject<USceneComponent>(TEXT("EndPosition"));
	//EndPosition->SetupAttachment(boxTrigger);

	IsOpen = NULL;

	DoorMoveDistance = 100.f;
	MoveInX = true;
}

void ARegularDoor::BeginPlay() {
	Super::BeginPlay();

	if (MoveInX) {
		DoorClosePosition = mesh->GetComponentLocation();
		DoorOpenPosition = FVector(DoorClosePosition.X + DoorMoveDistance, DoorClosePosition.Y, DoorClosePosition.Z);
	}
	else {
		DoorClosePosition = mesh->GetComponentLocation();
		DoorOpenPosition = FVector(DoorClosePosition.X , DoorClosePosition.Y + DoorMoveDistance, DoorClosePosition.Z);
	}
		
		
		if (DoorPanel != NULL) {
			IsOpen = DoorPanel->isOpen;

			if (IsOpen) {
				mesh->SetWorldLocation(DoorOpenPosition);
			}
			else {
				mesh->SetWorldLocation(DoorClosePosition);
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No door panel associated with the door."));
		}
}

void ARegularDoor::ToggleDoor( ) {
	Super::ToggleDoor();
	ToggleDoorRequest.Broadcast();

	IsOpen = !IsOpen;
	UE_LOG(LogTemp, Warning, TEXT("Time To Toggle Door"));
}
