// Fill out your copyright notice in the Description page of Project Settings.

#include "LockerKey.h"
#include "LockDown2Character.h"
#include "Kismet/GameplayStatics.h"

ALockerKey::ALockerKey() {
	LockerKeyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LockerKeyMesh"));
	LockerKeyMesh->SetupAttachment(SceneComponent);
}

void ALockerKey::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Picked up the locker key"));
	ALockDown2Character * PlayerCharacter = Cast<ALockDown2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (PlayerCharacter) {
		PlayerCharacter->bHasLockerKey = true;
	}
	//Update player animation state here and play animation
	//PlayerCharacter->PlayerAnimationState = EPlayerState::PS_LockerKeyPickUp;
	//PlayerCharacter->UpdateAnimationState(EPlayerState::PS_LockerKeyPickUp);
	//Also add delay here. 
	//Also add sockey in animation for the key...
	this->Destroy();
}
