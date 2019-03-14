// Fill out your copyright notice in the Description page of Project Settings.

#include "DrinkMachine.h"

// Sets default values
ADrinkMachine::ADrinkMachine()
{
	DrinkMachine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DrinkMachine"));
	DrinkMachine->SetupAttachment(SceneComponent);
	DrinkMachineCover = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DrinkMachineCover"));
	DrinkMachineCover->SetupAttachment(DrinkMachine);
}

void ADrinkMachine::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting with the Drink Machine"));
}

// Called when the game starts or when spawned
void ADrinkMachine::BeginPlay()
{
	Super::BeginPlay();
	
}


