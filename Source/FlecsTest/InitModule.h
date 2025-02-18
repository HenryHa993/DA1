// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealFlecsModuleBase.h"
#include "InitModule.generated.h"

/**
 * 
 */
UCLASS()
class FLECSTEST_API UInitModule : public UUnrealFlecsModuleBase
{
	GENERATED_BODY()

public:
	virtual void Initialise(flecs::world& ecs) override;
};
