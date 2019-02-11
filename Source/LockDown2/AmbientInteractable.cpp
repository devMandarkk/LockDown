// Fill out your copyright notice in the Description page of Project Settings.

#include "AmbientInteractable.h"

//Sets the default values
AAmbientInteractable::AAmbientInteractable() {
	UE_LOG(LogTemp, Warning, TEXT("Ambient Interactable"));

}

void AAmbientInteractable::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin - AAmbientInteractable"));

}

void AAmbientInteractable::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd - AAmbientInteractable"));
}
