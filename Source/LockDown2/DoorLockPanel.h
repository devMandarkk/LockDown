// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "Components/TextRenderComponent.h"
#include "DoorPanel.h"
#include "DoorLockPanel.generated.h"

/**
 * 
 */
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

protected:
	virtual void BeginPlay() override;

};
