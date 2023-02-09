// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyGameInstance.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(Cast<USceneComponent>(MeshComponent));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	Red = CreateDefaultSubobject<UMaterial>(TEXT("Red"));
	Blue = CreateDefaultSubobject<UMaterial>(TEXT("Blue"));
	Green = CreateDefaultSubobject<UMaterial>(TEXT("Green"));
	Yellow = CreateDefaultSubobject<UMaterial>(TEXT("Yellow"));
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}
void AMyPawn::stop()
{
	UE_LOG(LogTemp, Warning, TEXT("stop water flow"));
	UMaterialInstanceDynamic* r = UMaterialInstanceDynamic::Create(Red, GetWorld());
	MeshComponent->SetMaterial(0, r);
}
void AMyPawn::start1()
{
	UE_LOG(LogTemp, Warning, TEXT("water flow from tank 1"));
	UMaterialInstanceDynamic* y = UMaterialInstanceDynamic::Create(Yellow, GetWorld());
	MeshComponent->SetMaterial(0, y);
}
void AMyPawn::start2()
{
	UE_LOG(LogTemp, Warning, TEXT("water flow from tank 2"));
	UMaterialInstanceDynamic* b = UMaterialInstanceDynamic::Create(Blue, GetWorld());
	MeshComponent->SetMaterial(0, b);
}
void AMyPawn::start3()
{
	UE_LOG(LogTemp, Warning, TEXT("water flow from both tanks"));
	UMaterialInstanceDynamic* g = UMaterialInstanceDynamic::Create(Green, GetWorld());
	MeshComponent->SetMaterial(0, g);
}
void AMyPawn::start11()
{
	UMyGameInstance* GameInstance = Cast< UMyGameInstance>(GetGameInstance());

	if (GameInstance)
	{
		if (GameInstance->WebSocket->IsConnected())
		{
			GameInstance->WebSocket->Send("1");
		}
	}
}

void AMyPawn::start22()
{
	UMyGameInstance* GameInstance = Cast< UMyGameInstance>(GetGameInstance());

	if (GameInstance)
	{
		if (GameInstance->WebSocket->IsConnected())
		{
			GameInstance->WebSocket->Send("2");
		}
	}
}

void AMyPawn::start33()
{
	UMyGameInstance* GameInstance = Cast< UMyGameInstance>(GetGameInstance());

	if (GameInstance)
	{
		if (GameInstance->WebSocket->IsConnected())
		{
			GameInstance->WebSocket->Send("3");
		}
	}
}

void AMyPawn::stop00()
{
	UMyGameInstance* GameInstance = Cast< UMyGameInstance>(GetGameInstance());

	if (GameInstance)
	{
		if (GameInstance->WebSocket->IsConnected())
		{
			GameInstance->WebSocket->Send("0");
		}
	}
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UMyGameInstance* ws = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (ws->s == "0")
	{
		stop();
	}
	else if (ws->s == "1")
	{
		start1();
	}
	else if (ws->s == "2")
	{
		start2();
	}
	else if (ws->s == "3")
	{
		start3();
	}
	/* if (ws->s1 == "wet")
	{
		stop();
	}
	if (ws->s1 == "dry")
	{
		start33();
	}*/
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("stop", IE_Pressed, this, &AMyPawn::stop);
	PlayerInputComponent->BindAction("start1", IE_Pressed, this, &AMyPawn::start1);
	PlayerInputComponent->BindAction("start2", IE_Pressed, this, &AMyPawn::start2);
	PlayerInputComponent->BindAction("start3", IE_Pressed, this, &AMyPawn::start3);

	PlayerInputComponent->BindAction("start1", IE_Pressed, this, &AMyPawn::start11);
	PlayerInputComponent->BindAction("start2", IE_Pressed, this, &AMyPawn::start22);
	PlayerInputComponent->BindAction("start3", IE_Pressed, this, &AMyPawn::start33);
	PlayerInputComponent->BindAction("stop", IE_Pressed, this, &AMyPawn::stop00);

}

