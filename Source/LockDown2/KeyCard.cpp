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
	//Update player animation state here and play animation
	/*FRotator CurrentRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();
	GetWorld()->GetFirstPlayerController()->SetControlRotation(FRotator(CurrentRotation.Pitch, CurrentRotation.Yaw, CurrentRotation.Roll));
*/

	PlayerCharacter->UpdateAnimationState(EPlayerState::PS_KeyCardPickUp);
	//FRotator test = FRotator(0.f, 0.f, 0.f);
	//PlayerCharacter->FirstPersonCameraComponent->RelativeRotation += FRotator(0, 0, 25.f);
	

	/*	FQuat QuatRotation = FQuat(FRotator(0.f, 0.f, 180.f));
		PlayerCharacter->SetActorRotation(QuatRotation);*/


	this->Destroy();

}
