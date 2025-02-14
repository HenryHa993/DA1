// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "flecs.h"
#include "UnrealFlecsBootstrap.generated.h"

UCLASS()
class UNREALFLECS_API AUnrealFlecsBootstrap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUnrealFlecsBootstrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Bootstrap(flecs::world& ecs);
};
