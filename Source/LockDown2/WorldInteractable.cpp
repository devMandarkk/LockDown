// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldInteractable.h"

//Sets the default values
AWorldInteractable::AWorldInteractable() {
	UE_LOG(LogTemp, Warning, TEXT("World Interactable"));
}

void AWorldInteractable::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin - AWorldInteractable"));

}
void AWorldInteractable::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd - AWorldInteractable"));

}