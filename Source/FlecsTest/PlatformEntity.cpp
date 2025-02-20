// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformEntity.h"


// Sets default values
APlatformEntity::APlatformEntity()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneRoot;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void APlatformEntity::BeginPlay()
{
	Super::BeginPlay();
}

void APlatformEntity::Initialise()
{
	Entity.set<OwningActor>({this})
		.set<Timer>({0})
		.set<Transform>({GetActorTransform()})
		.set<LocalTransform>({StaticMesh->GetRelativeTransform()})
		.set<StaticMeshComponent>({StaticMesh})
		.set<OscillationSpeed>({Speed})
		.set<OscillationDistance>({Distance})
		.set<PaintColours>({Colours});

	for(EOscillationType type : Oscillations)
	{
		switch (type)
		{
		case EOscillationType::None:
			break;
		case EOscillationType::Red:
			Entity.add<XOscillator>();
			break;
		case EOscillationType::Green:
			Entity.add<YOscillator>();
			break;
		case EOscillationType::Blue:
			Entity.add<ZOscillator>();
			break;
		}
	}
}
