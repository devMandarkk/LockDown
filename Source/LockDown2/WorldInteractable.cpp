// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldInteractable.h"

//Sets the default values
AWorldInteractable::AWorldInteractable() {
	UE_LOG(LogTemp, Warning, TEXT("World Interactable"));
	//mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}

void AWorldInteractable::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp,  OtherBodyIndex,  bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin - AWorldInteractable"));

}
void AWorldInteractable::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd - AWorldInteractable"));

}

void AWorldInteractable::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("world interactable on interact"));

}

void AWorldInteractable::OnHoverOver()
{
	CreateTheOutline.Broadcast();
}

void AWorldInteractable::OnHoverOff()
{
	TurnOffOutline.Broadcast();
}

void AWorldInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
