// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldInteractable.h"
#include "BaseDoorClass.generated.h"

UCLASS()
class LOCKDOWN2_API ABaseDoorClass : public AWorldInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseDoorClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DoorOpenDelay;
	virtual void ToggleDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
