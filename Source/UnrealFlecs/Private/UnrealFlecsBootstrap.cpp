// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealFlecsBootstrap.h"

#include "UnrealFlecsSubsystem.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AUnrealFlecsBootstrap::AUnrealFlecsBootstrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AUnrealFlecsBootstrap::BeginPlay()
{
	UGameInstance* gameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UUnrealFlecsSubsystem* flecsSubsystem = gameInstance->GetSubsystem<UUnrealFlecsSubsystem>();
	Bootstrap(*flecsSubsystem->GetEcsWorld());
	Super::BeginPlay();
}

void AUnrealFlecsBootstrap::Bootstrap(flecs::world& ecs)
{
}
