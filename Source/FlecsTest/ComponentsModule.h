// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealFlecsModuleBase.h"
#include "ComponentsModule.generated.h"

struct Transform
{
	FTransform Value;
};

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
