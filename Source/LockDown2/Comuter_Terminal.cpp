// Fill out your copyright notice in the Description page of Project Settings.

#include "Comuter_Terminal.h"
#include "Kismet/GameplayStatics.h"

AComuter_Terminal::AComuter_Terminal() {
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	mesh->SetupAttachment(SceneComponent);
	keyboard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("keyboard"));
	keyboard->SetupAttachment(mesh);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(mesh);

	bSwitchCamera = false;
}
void AComuter_Terminal::BeginPlay()
{
	Super::BeginPlay();
	this->ToggleCamera.AddDynamic(this, &AComuter_Terminal::CameraToggle);
}
void AComuter_Terminal::CameraToggle()
{
	UE_LOG(LogTemp, Warning, TEXT("Camera Toggle firing through events"));
	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	//TimeToNextCameraChange -= DeltaTime;
	//if (TimeToNextCameraChange <= 0.0f)
	//{
		//TimeToNextCameraChange += TimeBetweenCameraChanges;

		// Find the actor that handles control for the local player.
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (OurPlayerController)
	{
		//FMinimalViewInfo * testView = NULL;
			//camera->GetCameraView(.1f, testView);
		if ((OurPlayerController->GetViewTarget() != PlayerCamera) && (PlayerCamera != nullptr) && !bSwitchCamera)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Time to switch Camera to person"));

			// Cut instantly to camera one.
			OurPlayerController->SetViewTargetWithBlend(PlayerCamera, SmoothBlendTime);
		}
		else if ((OurPlayerController->GetViewTarget() != this) && (this != nullptr) && bSwitchCamera)
		{
			UE_LOG(LogTemp, Warning, TEXT("Time to switch Camera to panel"));

			// Blend smoothly to camera two.
			OurPlayerController->SetViewTargetWithBlend(this, SmoothBlendTime);
		}
	}
}

void AComuter_Terminal::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Trigger entered"));
	//bSwitchCamera = true;
	//ToggleCamera.Broadcast();

}

void AComuter_Terminal::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("Trigger exited"));
	//bSwitchCamera = false;
	//ToggleCamera.Broadcast();
}

void AComuter_Terminal::OnInteract()
{
	Super::OnInteract();
	UE_LOG(LogTemp, Warning, TEXT("interacting virtuall"));
	bSwitchCamera = !bSwitchCamera;
	ToggleCamera.Broadcast();

}

