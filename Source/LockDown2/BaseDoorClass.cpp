// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseDoorClass.h"

// Sets default values
ABaseDoorClass::ABaseDoorClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseDoorClass::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseDoorClass::ToggleDoor()
{
}

// Called every frame
void ABaseDoorClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

