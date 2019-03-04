// Fill out your copyright notice in the Description page of Project Settings.

#include "ExaminableInteractable.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "GameFramework/Character.h"

AExaminableInteractable::AExaminableInteractable() {
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	RootComponent = MyMesh;

	MyMesh->SetSimulatePhysics(true);
	//MyMesh->SetupAttachment(SceneComponent);


	//RootComponent = MyMesh;
	//MyMesh->SetupAttachment(SceneComponent);
	//boxTrigger->SetupAttachment(MyMesh);
	//boxTrigger->SetupAttachment(MyMesh);
	//MyMesh->SetupAttachment(boxTrigger);
	bHolding = false;
	bGravity = true;

	//UMaterialInstanceDynamic * MaterialInstance = MyMesh->CreateDynamicMaterialInstance(0);

}
void AExaminableInteractable::SpawnPutBackVolume()
{
	if (ToSpawn) {
		UWorld * world = GetWorld();

		if (world) {
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			PutBackVolume = world->SpawnActor<APutBackVolumeActor>(ToSpawn, GetActorLocation(), GetActorRotation(), spawnParams);
			PutBackVolume->SetActorHiddenInGame(true);
		}
	}
}
void AExaminableInteractable::SetPutBack(bool value)
{
	bPutBack = value;
}
void AExaminableInteractable::BeginPlay()
{
	Super::BeginPlay();
	//StartPosition = 
	//FVector test = GetOwner()->GetActorLocation();
	//MyMesh->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("pickup world location is %s"), MyMesh->GetComponentLocation().ToString());


	FVector Location = MyMesh->GetComponentLocation();
	FString text = Location.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Location.ToString());


	MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	PlayerCamera = MyCharacter->FindComponentByClass<UCameraComponent>();

	TArray<USceneComponent*> Components;

	MyCharacter->GetComponents(Components);

	if (Components.Num() > 0) {
		for (auto& Comp : Components) {
			if (Comp->GetName() == "HoldingComponent") {
				HoldingComp = Cast<USceneComponent>(Comp);
			}
		}
	}

	////MaterialInstance->SetScalarParameterValue(FName("Value"), 0.0f);

	//if (MaterialInstance) {
	//	UE_LOG(LogTemp, Warning, TEXT("1"));
	//	//MaterialInstance->SetScalarParameterValue(FName("Value"), 1.0f);
	//}
	//else {
	//	UE_LOG(LogTemp, Warning, TEXT("2"));
	//}
}
void AExaminableInteractable::RotateActor()
{
	ControlRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();
	SetActorRotation(FQuat(ControlRotation));
}

void AExaminableInteractable::Pickup()
{
	//UE_LOG(LogTemp, Warning, TEXT("pickup function called"));

	bHolding = !bHolding;
	bGravity = !bGravity;
	MyMesh->SetEnableGravity(bGravity);
	MyMesh->SetSimulatePhysics(bHolding ? false : true);
	MyMesh->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);

	if (!bHolding) {
		if (bPutBack) {
			SetActorLocationAndRotation(Location, Rotation, false, 0, ETeleportType::None);
			bPutBack = false;
		}
		else {
			ForwardVector = PlayerCamera->GetForwardVector();
			MyMesh->AddForce(ForwardVector * 100000 * MyMesh->GetMass());
			bPutBack = false;

		}
		if (PutBackVolume) {
			PutBackVolume->Destroy();
		}
	}
	else {
		Location = GetActorLocation();
		Rotation = GetActorRotation();
		SpawnPutBackVolume();

	}
}

void AExaminableInteractable::Tick(float DeltaTime)
{
	if (bHolding && HoldingComp) {
	
		SetActorLocationAndRotation(HoldingComp->GetComponentLocation(), HoldingComp->GetComponentRotation());
	}
}

void AExaminableInteractable::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin - AExaminableInteractable"));
}

void AExaminableInteractable::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd - AExaminableInteractable"));
}


