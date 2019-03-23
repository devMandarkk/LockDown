// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "Camera/CameraComponent.h"
#include "Comuter_Terminal.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleComputerCamera);

UCLASS()
class LOCKDOWN2_API AComuter_Terminal : public AWorldInteractable
{
	GENERATED_BODY()

public:
	AComuter_Terminal();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * keyboard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent * Camera;

	UPROPERTY(EditAnywhere)
		AActor * PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bSwitchCamera;

	UPROPERTY()
	FToggleComputerCamera ToggleCamera;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	virtual void OnInteract() override;

	UFUNCTION()
	void CameraToggle();
protected:
	virtual void BeginPlay() override;

};
