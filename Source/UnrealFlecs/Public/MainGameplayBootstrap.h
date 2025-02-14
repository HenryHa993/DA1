// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealFlecsBootstrap.h"
#include "UnrealFlecsModuleBase.h"
#include "MainGameplayBootstrap.generated.h"

UCLASS()
class UNREALFLECS_API AMainGameplayBootstrap : public AUnrealFlecsBootstrap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UUnrealFlecsModuleBase>> FlecsModules;

protected:
	virtual void Bootstrap(flecs::world& ecs) override;

};
