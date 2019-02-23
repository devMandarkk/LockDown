// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "Components/TextRenderComponent.h"
#include "DoorPanel.h"
#include "Camera/CameraComponent.h"
#include "DoorLockPanel.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleCamera);

UCLASS()
class LOCKDOWN2_API ADoorLockPanel : public AWorldInteractable
{
	GENERATED_BODY()
	
public:
	ADoorLockPanel();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent * mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextRenderComponent* InputText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ADoorPanel * DoorPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent * Camera;

	UPROPERTY(BlueprintAssignable)
	FToggleCamera ToggleCamera;

	UPROPERTY(EditAnywhere)
	AActor* PlayerCamera;

	bool bSwitchCamera;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;


	FString correctPassword;
	FString currentPassword;
	FString displayPassword;
	int32 inputNumCount;

	void OnInteract();

	void UpdateUIAndCheckPassword();

	//Input handling functions
	void OnOnePressed();
	void OnTwoPressed();
	void OnThreePressed();
	void OnFourPressed();
	void OnFivePressed();
	void OnSixPressed();
	void OnSevenPressed();
	void OnEightPressed();
	void OnNinePressed();

	UFUNCTION()
	void CameraToggle();

protected:
	virtual void BeginPlay() override;

};
