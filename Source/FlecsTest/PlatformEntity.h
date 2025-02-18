// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/EntityBase.h"
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
};
