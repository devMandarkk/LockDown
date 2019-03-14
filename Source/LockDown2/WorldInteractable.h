// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/StaticMeshComponent.h"
#include "WorldInteractable.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTogglePPOutline);

UCLASS()
class LOCKDOWN2_API AWorldInteractable : public AInteractable
{
	GENERATED_BODY()
	
public:
	//Constructor
	AWorldInteractable();

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	virtual void OnInteract();

	UPROPERTY(EditAnywhere)
	FString ItemName;

	void OnHoverOver();
	void OnHoverOff();

	UPROPERTY(BlueprintAssignable)
	FTogglePPOutline CreateTheOutline;

	UPROPERTY(BlueprintAssignable)
	FTogglePPOutline TurnOffOutline;

protected:
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//UStaticMeshComponent * mesh;
};
