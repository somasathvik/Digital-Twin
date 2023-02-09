// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class DI1_API AMyPawn : public APawn
{
	GENERATED_BODY()
		/** Mesh component to give the Pawn a visual representation inthe world */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* MeshComponent;
	/** Camera boom positioning the camera behind the Pawn */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere)
		class UMaterial* Red;
	UPROPERTY(EditAnywhere)
		class UMaterial* Blue;
	UPROPERTY(EditAnywhere)
		class UMaterial* Green;
	UPROPERTY(EditAnywhere)
		class UMaterial* Yellow;


public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void stop();
	void start1();
	void start2();
	void start3();

	void start11();
	void start22();
	void start33();
	void stop00();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
