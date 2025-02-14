// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameplayBootstrap.h"

void AMainGameplayBootstrap::Bootstrap(flecs::world& ecs)
{
	for(auto moduleType : FlecsModules)
	{
		auto module = NewObject<UUnrealFlecsModuleBase>(this, moduleType); // Creating UObjects at runtime, the bootstrap is the owner
		module->Initialise(ecs);
	}
}
