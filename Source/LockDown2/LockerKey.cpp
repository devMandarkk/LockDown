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
	this->Destroy();
}
