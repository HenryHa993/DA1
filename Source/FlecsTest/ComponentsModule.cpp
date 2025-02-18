// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentsModule.h"

void UComponentsModule::Initialise(flecs::world& ecs)
{
	// Flecs has automatic registration, so no longer need to specifically register components.
}
