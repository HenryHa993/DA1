// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "flecs.h"
#include "UnrealFlecsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UNREALFLECS_API UUnrealFlecsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable)
	virtual void Deinitialize() override;
	flecs::world* GetEcsWorld() const;

protected:
	FTickerDelegate OnTickDelegate;
	FTSTicker::FDelegateHandle OnTickHandle;
	flecs::world* ECSWorld = nullptr;
private:
	bool Tick(float DeltaTime);
};
