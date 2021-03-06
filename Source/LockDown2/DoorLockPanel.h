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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextRenderComponent* InputText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ADoorPanel * DoorPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent * Camera;

	UPROPERTY(BlueprintAssignable)
	FToggleCamera ToggleCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInterface * lockMaterialGreen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInterface * lockMaterialRed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInterface * lockMaterialYellow;

	FTimerHandle MemberTimerHandle;

	UPROPERTY(EditAnywhere)
	AActor* PlayerCamera;

	bool bSwitchCamera;
	bool bAllowInput;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;


	FString correctPassword;
	FString currentPassword;
	FString displayPassword;
	int32 inputNumCount;

	virtual void OnInteract() override;

	void UpdateUIAndCheckPassword();
	void ResetOnFailure();

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

	//Sound related things below:
	//Sound that I need:
/*
- key pad input sound
- key pad failure sound
- key pad success sound
*/

	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase * InputDigitSound;
	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase * PasswordFailureSound;
	UPROPERTY(EditAnywhere, Category = Sound)
	USoundBase * PasswordSuccessSound;

	FTimerHandle SoundTimerHandle;

	UPROPERTY(EditAnywhere, Category = Sound)
		float InputDigitSoundDelay;

	UPROPERTY(EditAnywhere, Category = Sound)
		float PasswordFailureSoundDelay;

	UPROPERTY(EditAnywhere, Category = Sound)
		float PasswordSuccessSoundDelay;

	void PlayInputSound();
	void PlayFailureSound();
	void PlaySucessSound();

protected:
	virtual void BeginPlay() override;

};
