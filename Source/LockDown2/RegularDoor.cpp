// Fill out your copyright notice in the Description page of Project Settings.

#include "RegularDoor.h"

ARegularDoor::ARegularDoor() {
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	mesh->SetupAttachment(boxTrigger);

	StartPosition = CreateDefaultSubobject<USceneComponent>(TEXT("StartPosition"));
	StartPosition->SetupAttachment(boxTrigger);
	EndPosition = CreateDefaultSubobject<USceneComponent>(TEXT("EndPosition"));
	EndPosition->SetupAttachment(boxTrigger);

	IsOpen = NULL;
}

void ARegularDoor::BeginPlay() {
	Super::BeginPlay();
	DoorClosePosition = StartPosition->GetComponentLocation();
	DoorOpenPosition = EndPosition->GetComponentLocation();

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


	//UE_LOG(LogTemp, Warning, TEXT("DoorClosePosition's Location is %s"), *DoorClosePosition.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("DoorOpenPosition's Location is %s"), *DoorOpenPosition.ToString());

}

void ARegularDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//FVector test = EndPosition->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("End position X:%f, Y:%f, Z:%f"), &test.X, &test.Y, &test.Z);
	//UE_LOG(LogTemp, Warning, TEXT("found no door panel"));
	//FVector tes1 = StartPosition->GetComponentLocation();

	//UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Location is %s"), *tes1.ToString());

}

void ARegularDoor::ToggleDoor( ) {
	ToggleDoorRequest.Broadcast();

	IsOpen = !IsOpen;
	UE_LOG(LogTemp, Warning, TEXT("Time To Toggle Door"));
}
