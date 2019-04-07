// Fill out your copyright notice in the Description page of Project Settings.

#include "Locker.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

ALocker::ALocker() {
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	mesh->SetupAttachment(boxTrigger);

	LockerNumMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LockerNumMesh"));
	LockerNumMesh->SetupAttachment(mesh);

	LockerDoorLockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LockerDoorLockMesh"));
	LockerDoorLockMesh->SetupAttachment(mesh);

	AnimationPositionPointer = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AnimationPositionPointer"));
	AnimationPositionPointer->SetupAttachment(mesh);

}



void ALocker::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = Cast<ALockDown2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

}
void ALocker::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Time To Open Locker"));

	PlayerCharacter->SetActorLocation(AnimationPositionPointer->GetComponentLocation());

	PlayerCharacter->UpdateAnimationState(EPlayerState::PS_LockerKey);
	ToggleDoorRequest.Broadcast();
}