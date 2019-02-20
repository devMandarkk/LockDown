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


}
void ADoorPanel::OnInteract()
{
	if (RegularDoor) {
		//UE_LOG(LogTemp, Warning, TEXT("Time To Toggle Door"));
		isOpen = !isOpen;
		RegularDoor->ToggleDoor();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Door associated with panel"));

	}
}



void ADoorPanel::Tick(float DeltaTime)
{

}