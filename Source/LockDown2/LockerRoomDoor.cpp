// Fill out your copyright notice in the Description page of Project Settings.

#include "LockerRoomDoor.h"

ALockerRoomDoor::ALockerRoomDoor() {

	DoorRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorRight"));
	DoorRight->SetupAttachment(SceneComponent);
	DoorLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLeft"));
	DoorLeft->SetupAttachment(SceneComponent);

	IsOpen = NULL;

	DoorMoveDistance = 100.f;
}

void ALockerRoomDoor::BeginPlay()
{
	Super::BeginPlay();

	RightDoorClosePosition = DoorRight->GetComponentLocation();
	LeftDoorClosePosition = DoorLeft->GetComponentLocation();

	RightDoorOpenPosition = FVector(RightDoorClosePosition.X, RightDoorClosePosition.Y + DoorMoveDistance, RightDoorClosePosition.Z);
	LeftDoorOpenPosition = FVector(LeftDoorClosePosition.X, LeftDoorClosePosition.Y - DoorMoveDistance, LeftDoorClosePosition.Z);

	if (DoorPanel != NULL) {
		IsOpen = DoorPanel->isOpen;
		if (IsOpen) {
			//Set door right and door left to their open position
			DoorRight->SetWorldLocation(RightDoorOpenPosition);
			DoorLeft->SetWorldLocation(LeftDoorOpenPosition);
		}
		else {
			//Set door right and door left to their close position
			DoorRight->SetWorldLocation(RightDoorClosePosition);
			DoorLeft->SetWorldLocation(LeftDoorClosePosition);
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No door panel associated with the Locker Room door."));

	}
}

void ALockerRoomDoor::ToggleDoor()
{
	ToggleDoorRequest.Broadcast();
	IsOpen = !IsOpen;
	UE_LOG(LogTemp, Warning, TEXT("Time to toggle locker room door"));

}