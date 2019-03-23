// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "BaseDoorClass.h"
#include "LockDown2Character.h"
#include "DoorPanel.generated.h"

/**
 * 
 */
UCLASS()
class LOCKDOWN2_API ADoorPanel : public AWorldInteractable
{
	GENERATED_BODY()

public:

	//Constructor
	ADoorPanel();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* btnMesh;

	UPROPERTY(EditAnywhere)
	bool isOpen;

	UPROPERTY(EditAnywhere)
	bool IsLocked;

	UPROPERTY(EditAnywhere)
	bool IsElevatorPanel;

	UPROPERTY(EditAnywhere)
	class ABaseDoorClass * PanelDoor;

	UPROPERTY(EditAnywhere)
	class ALockDown2Character * PlayerCharacter;

	virtual void OnInteract() override;
	void UnlockDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface * lockMaterialGreen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface * lockMaterialRed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface * lockMaterialGrey;

	void UpdateMaterial(bool IsLocked);
protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
