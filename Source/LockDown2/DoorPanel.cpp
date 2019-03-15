// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorPanel.h"

ADoorPanel::ADoorPanel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	mesh->SetupAttachment(boxTrigger);
	btnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BtnMesh"));
	btnMesh->SetupAttachment(mesh);
	//RootComponent = mesh;
	//name = "Door Panel";
	//isOpen = false;
	//isOpen = false;
}

void ADoorPanel::BeginPlay()
{
	Super::BeginPlay();

	if (isOpen) {
		UE_LOG(LogTemp, Warning, TEXT("Door Open at start"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Door closed at start"));
	}

	UpdateMaterial(IsLocked);
}
void ADoorPanel::OnInteract()
{
	Super::OnInteract();
	if (!IsLocked) {
		if (RegularDoor) {
			//UE_LOG(LogTemp, Warning, TEXT("Time To Toggle Door"));
			isOpen = !isOpen;
			RegularDoor->ToggleDoor();
		}
		if (RegularDoor2) {
			//UE_LOG(LogTemp, Warning, TEXT("Time To Toggle Door"));
			isOpen = !isOpen;
			RegularDoor2->ToggleDoor();
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No Door associated with panel"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Door is locked!"));
	}

}


void ADoorPanel::UpdateMaterial(bool IsLocked)
{
	//red light material index is - 1
	//green light material index is - 5
	if (IsLocked) {
		//It is locked - Red light needs to be on, the other should be default
		mesh->SetMaterial(1, lockMaterialRed);
		mesh->SetMaterial(5, lockMaterialGrey);
	}
	else {
		//It is unlocked - Green light needs to be on, the other should be default. 
		mesh->SetMaterial(1, lockMaterialGrey);
		mesh->SetMaterial(5, lockMaterialGreen);
	}
}

void ADoorPanel::Tick(float DeltaTime)
{

}
void ADoorPanel::UnlockDoor(){
	UE_LOG(LogTemp, Warning, TEXT("Door Unlocked from Door Panel"));

	IsLocked = false;
	UpdateMaterial(IsLocked);

}