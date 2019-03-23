// Fill out your copyright notice in the Description page of Project Settings.

#include "KeyCard.h"
#include "LockDown2Character.h"
#include "Kismet/GameplayStatics.h"



AKeyCard::AKeyCard() {
	KeyCardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyCardMesh"));
	KeyCardMesh->SetupAttachment(SceneComponent);

}

void AKeyCard::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Picked up the key card"));
	//also update player class here to have the card
	ALockDown2Character * PlayerCharacter = Cast<ALockDown2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if(PlayerCharacter){
		PlayerCharacter->bHasKey = true;
	}
	this->Destroy();

}
