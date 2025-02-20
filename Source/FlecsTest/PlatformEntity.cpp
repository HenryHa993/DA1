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
	PivotPoint = GetActorLocation();
	Super::BeginPlay();
}

void APlatformEntity::Initialise()
{
	Entity.set<OwningActor>({this})
		.set<Pivot>({PivotPoint})
		.set<Transform>({GetActorTransform()})
		.set<StaticMeshComponent>({StaticMesh})
		.set<PaintColours>({Colours});
}
