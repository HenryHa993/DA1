// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "flecs.h"
#include "UnrealFlecsModuleBase.generated.h"

/**
 * 
 */
UCLASS()
class UNREALFLECS_API UUnrealFlecsModuleBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void Initialise(flecs::world& ecs);
};
