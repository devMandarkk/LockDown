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
	if(PlayerCharacter->bHasLockerKey){
		UE_LOG(LogTemp, Warning, TEXT("Time To Open Locker"));

		FRotator CurrentRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();
		//GetWorld()->GetFirstPlayerController()->SetControlRotation(FRotator(CurrentRotation.Roll, 179.f, CurrentRotation.Pitch));
		if (AnimationRotateDirection) {

			if (AnimationRotateDirection) {
				GetWorld()->GetFirstPlayerController()->SetControlRotation(FRotator(CurrentRotation.Pitch, AnimationRotateDirection, CurrentRotation.Roll));
				//GetWorld()->GetFirstPlayerController()
				DisableInput(GetWorld()->GetFirstPlayerController());
			}
		}
		PlayerCharacter->SetActorLocation(AnimationPositionPointer->GetComponentLocation());

		PlayerCharacter->UpdateAnimationState(EPlayerState::PS_LockerKey);
		//ToggleDoorRequest.Broadcast();
	}
	else {
		//on locker key
	}

}