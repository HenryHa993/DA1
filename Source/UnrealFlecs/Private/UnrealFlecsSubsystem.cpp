// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealFlecsSubsystem.h"

void UUnrealFlecsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	OnTickDelegate = FTickerDelegate::CreateUObject(this, &UUnrealFlecsSubsystem::Tick);
	OnTickHandle = FTSTicker::GetCoreTicker().AddTicker(OnTickDelegate);

	ECSWorld = new flecs::world();
	
	//sets title in Flecs Explorer
	/*char name[] = { "Game Design and Analytics" };
	char* argv = name;
	ECSWorld = new flecs::world(1, &argv);*/
	
	//flecs explorer and monitor
	//comment this out if you not using it, it has some performance overhead
	//go to https://www.flecs.dev/explorer/ when the project is running to inspect active entities and values
	/*GetEcsWorld()->import<flecs::monitor>();
	GetEcsWorld()->set<flecs::Rest>({});*/
	
	//expose values with names to Flecs Explorer for easier inspection & debugging
	/*GetEcsWorld()->component<FlecsCorn>().member<float>("Current Growth");
	GetEcsWorld()->component<FlecsISMIndex>().member<int>("ISM Render index");	*/
	
	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has started!!"));
	Super::Initialize(Collection);}

void UUnrealFlecsSubsystem::Deinitialize()
{
	FTSTicker::GetCoreTicker().RemoveTicker(OnTickHandle);
	
	if (ECSWorld)
	{
		delete ECSWorld;
		ECSWorld = nullptr;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has shut down!"));
	Super::Deinitialize();
}

flecs::world* UUnrealFlecsSubsystem::GetEcsWorld() const
{
	return ECSWorld;
}

// Runs systems registered to pipeline
bool UUnrealFlecsSubsystem::Tick(float DeltaTime)
{
	if(ECSWorld) ECSWorld->progress(DeltaTime);
	return true;
}
