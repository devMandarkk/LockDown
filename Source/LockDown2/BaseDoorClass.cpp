// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseDoorClass.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Sets default values
ABaseDoorClass::ABaseDoorClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DoorOpenDelay = 0.0f;
	DoorSoundDelay = 0.0f;

}

// Called when the game starts or when spawned
void ABaseDoorClass::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseDoorClass::PlaySound()
{
	if (DoorSound) {
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), DoorSound, GetActorLocation(), 1.0f, 1.0f, .0f);
	}
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void ABaseDoorClass::ToggleDoor()
{
	GetWorldTimerManager().SetTimer(SoundTimerHandle, this, &ABaseDoorClass::PlaySound, DoorSoundDelay, true);

}

// Called every frame
void ABaseDoorClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

