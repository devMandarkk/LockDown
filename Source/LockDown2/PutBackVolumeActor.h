// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PutBackVolumeActor.generated.h"

UCLASS()
class LOCKDOWN2_API APutBackVolumeActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APutBackVolumeActor();

	UPROPERTY(EditAnywhere)
		USceneComponent * SceneComponent;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent * Mesh;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
