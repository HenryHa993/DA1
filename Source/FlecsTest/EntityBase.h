// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Union.h"
#include "FlecsTest/ComponentsModule.h"
#include "GameFramework/Actor.h"
#include "UObject/ObjectRename.h"
#include "EntityBase.generated.h"

UENUM(BlueprintType)
enum class EComponent : uint8
{
	ActorComponent,
	TransformComponent
};

USTRUCT(BlueprintType)
struct FComponent
{
	GENERATED_BODY()

	EComponent Component;

	TUnion<OwningActor*, Transform> ComponentValue;
};

UCLASS()
class FLECSTEST_API AEntityBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEntityBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Initialise();

public:
	template <typename T>
	void AddComponent(T value = T());

public:
	flecs::entity Entity;

protected:
	flecs::world* ecs;
};

template <typename T>
void AEntityBase::AddComponent(T value)
{
	Entity.set<T>(value);
}
