// Fill out your copyright notice in the Description page of Project Settings.

#include "PutBackVolumeActor.h"

// Sets default values
APutBackVolumeActor::APutBackVolumeActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SceneComponent);
}

// Called when the game starts or when spawned
void APutBackVolumeActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APutBackVolumeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

