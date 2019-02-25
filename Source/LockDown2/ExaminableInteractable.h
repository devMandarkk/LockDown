// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "ExaminableInteractable.generated.h"

/**
 * 
 */
UCLASS()
class LOCKDOWN2_API AExaminableInteractable : public AWorldInteractable
{
	GENERATED_BODY()

public:
	AExaminableInteractable();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
		USceneComponent* HoldingComp;

	UPROPERTY(EditAnywhere)
		FTransform StartPosition;

	UFUNCTION()
		void RotateActor();

	UFUNCTION()
		void Pickup();

	bool bHolding;
	bool bGravity;

	FRotator ControlRotation;
	ACharacter* MyCharacter;
	UCameraComponent* PlayerCamera;
	FVector ForwardVector;

	virtual void Tick(float DeltaTime) override;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

protected:

	virtual void BeginPlay() override;

};
