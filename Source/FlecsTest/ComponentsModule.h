// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealFlecsModuleBase.h"
#include "ComponentsModule.generated.h"

// Components
struct OwningActor
{
	AActor* Value;
};

struct StaticMeshComponent
{
	UStaticMeshComponent* Value;
};

struct Transform
{
	FTransform Value;
};

struct LocalTransform
{
	FTransform Value;
};

struct Timer
{
	float Value;
};

struct PaintColours
{
	TArray<UMaterialInstance*> Value;
};

// Tags
struct ZOscillator{};

struct XOscillator{};

struct YOscillator{};

struct SetColour{};

/**
 * 
 */
UCLASS()
class FLECSTEST_API UComponentsModule : public UUnrealFlecsModuleBase
{
	GENERATED_BODY()

public:
	virtual void Initialise(flecs::world& ecs) override;
};
