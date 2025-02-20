// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntityBase.h"
#include "PlatformEntity.generated.h"

UCLASS()
class FLECSTEST_API APlatformEntity : public AEntityBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlatformEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Initialise() override;

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInstance*> Colours;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PivotPoint;
};
