// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SceneComponent->SetupAttachment(RootComponent);
	boxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxTrigger"));
	boxTrigger->SetupAttachment(SceneComponent);


}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	boxTrigger->OnComponentBeginOverlap.AddDynamic(this, &AInteractable::OnOverlapBegin);
	boxTrigger->OnComponentEndOverlap.AddDynamic(this, &AInteractable::OnOverlapEnd);
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractable::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin - AInteractable"));
}

void AInteractable::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd - AInteractable"));

}



void AInteractable::BeginInteraction()
{
}

bool AInteractable::InteractionCheck()
{
	return false;
}



