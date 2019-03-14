// Fill out your copyright notice in the Description page of Project Settings.

#include "FoodMachine.h"

AFoodMachine::AFoodMachine() {
	FoodMachine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FoodMachine"));
	FoodMachine->SetupAttachment(SceneComponent);

	FoodMachineCover = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FoodMachineCover"));
	FoodMachineCover->SetupAttachment(FoodMachine);
}

void AFoodMachine::BeginPlay(){
	Super::BeginPlay();
}


void AFoodMachine::OnInteract(){
	UE_LOG(LogTemp, Warning, TEXT("Interacting with the Food Machine"));

}

