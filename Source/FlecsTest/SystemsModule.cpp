// Fill out your copyright notice in the Description page of Project Settings.


#include "SystemsModule.h"

#include "ComponentsModule.h"

void USystemsModule::Initialise(flecs::world& ecs)
{
	// If you do not want it registered to a timeline, set kind(0)
	testSys = ecs.system<Transform>("Test System")
		.each([](Transform& t)
		{
			UE_LOG(LogTemp, Warning, TEXT("Transform %s"), *t.Value.ToString());
		});
}