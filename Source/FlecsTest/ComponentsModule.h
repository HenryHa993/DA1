// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealFlecsModuleBase.h"
#include "ComponentsModule.generated.h"

// Components
struct Transform
{
	FTransform Value;
};

struct LocalTransform
{
	FTransform Value;
};

struct ActorPtr
{
	AActor* Value;
};

// Tags
struct UpDownMove{};

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
