// Fill out your copyright notice in the Description page of Project Settings.

#include "ElevatorDoorLockPanel.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AElevatorDoorLockPanel::AElevatorDoorLockPanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	mesh->SetupAttachment(SceneComponent);
}



// Called when the game starts or when spawned
void AElevatorDoorLockPanel::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = Cast<ALockDown2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

}

void AElevatorDoorLockPanel::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("interacting with elevator door panel"));
	if (PlayerCharacter->bHasKey) {
		//if has key is true and the door is still locked it means we need to 
		//play unlock door hand animation
		//update the lock panel mterial to green.

		UE_LOG(LogTemp, Warning, TEXT("player just unlocked the elevator"));
		PlayerCharacter->UpdateAnimationState(EPlayerState::PS_ElevatorSwipe);

		DoorPanel->UnlockDoor();

	}
	else {
		//if has key is false play button push animation with no change. 
		UE_LOG(LogTemp, Warning, TEXT("player doesnt have the key to open elevator"));

	}
}
// Called every frame
void AElevatorDoorLockPanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

