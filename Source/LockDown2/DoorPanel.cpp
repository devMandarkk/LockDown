// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorPanel.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


ADoorPanel::ADoorPanel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	mesh->SetupAttachment(boxTrigger);
	btnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BtnMesh"));
	btnMesh->SetupAttachment(mesh);

	AnimationPositionPointer = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AnimationPositionPointer"));
	AnimationPositionPointer->SetupAttachment(SceneComponent);
	//RootComponent = mesh;
	//name = "Door Panel";
	//isOpen = false;
	//isOpen = false;
}

void ADoorPanel::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerCharacter = Cast<ALockDown2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (isOpen) {
		//UE_LOG(LogTemp, Warning, TEXT("Door Open at start"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("Door closed at start"));
	}

	UpdateMaterial(IsLocked);

	

}
void ADoorPanel::OnInteract()
{
	Super::OnInteract();
	if (!IsLocked) {
		if (PanelDoor) {
			//UE_LOG(LogTemp, Warning, TEXT("Time To Toggle Door"));
			isOpen = !isOpen;
			PanelDoor->ToggleDoor();

			if (GetWorld()->GetFirstPlayerController()) {
				FQuat QuatRotation = FQuat(FRotator(0.f, 0.f, 0.f));
				GetWorld()->GetFirstPlayerController()->SetControlRotation(FRotator(0.f, 171.f, 0.f));

			}
			PlayerCharacter->SetActorLocation(AnimationPositionPointer->GetComponentLocation());

			PlayerCharacter->UpdateAnimationState(EPlayerState::PS_ButtonPush);

		/*	FQuat QuatRotation = FQuat(FRotator(0.f, 0.f, 180.f));
			PlayerCharacter->SetActorRotation(QuatRotation);*/
	
			//PlayerCharacter.
		}

		else {
			UE_LOG(LogTemp, Warning, TEXT("No Door associated with panel"));
		}
	}
	else {
		//Door is locked
		UE_LOG(LogTemp, Warning, TEXT("Regular door is locked!"));

		//if the door is an elevator door
		//if (IsElevatorPanel) {
	
		//	//Check if the player has the key

		//	if (PlayerCharacter->bHasKey) {
		//		//if has key is true and the door is still locked it means we need to 
		//		//play unlock door hand animation
		//		//update the lock panel mterial to green.

		//		IsLocked = false;
		//		UpdateMaterial(IsLocked);
		//		UE_LOG(LogTemp, Warning, TEXT("player just unlocked the elevator"));

		//	}
		//	else {
		//		//if has key is false play button push animation with no change. 
		//		UE_LOG(LogTemp, Warning, TEXT("player doesnt have the key to open elevator"));

		//	}
		//}
		//else {
		//UE_LOG(LogTemp, Warning, TEXT("Regular door is locked!"));
		////It is a regular door panel which is locked. 
		////Play the button push animation. 
		////Play negative audio.
		//}
	}

}


void ADoorPanel::UpdateMaterial(bool IsLocked)
{
	//red light material index is - 1
	//green light material index is - 5
	if (IsLocked) {
		//It is locked - Red light needs to be on, the other should be default
		mesh->SetMaterial(1, lockMaterialRed);
		mesh->SetMaterial(5, lockMaterialGrey);
	}
	else {
		//It is unlocked - Green light needs to be on, the other should be default. 
		mesh->SetMaterial(1, lockMaterialGrey);
		mesh->SetMaterial(5, lockMaterialGreen);
	}
}

void ADoorPanel::Tick(float DeltaTime)
{

}
void ADoorPanel::UnlockDoor(){
	UE_LOG(LogTemp, Warning, TEXT("Door Unlocked from Door Panel"));

	IsLocked = false;
	UpdateMaterial(IsLocked);

}