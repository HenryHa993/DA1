// Fill out your copyright notice in the Description page of Project Settings.


#include "EntityBase.h"

#include "UnrealFlecsSubsystem.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEntityBase::AEntityBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEntityBase::BeginPlay()
{
	UGameInstance* gameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UUnrealFlecsSubsystem* flecsSubsystem = gameInstance->GetSubsystem<UUnrealFlecsSubsystem>();
	ecs = flecsSubsystem->GetEcsWorld();
	Entity = ecs->entity();
	Initialise();
	
	Super::BeginPlay();
}

void AEntityBase::Initialise()
{
}