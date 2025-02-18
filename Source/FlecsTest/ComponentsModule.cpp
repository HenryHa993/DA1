// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentsModule.h"

void UComponentsModule::Initialise(flecs::world& ecs)
{
	ecs.component<Transform>();
}
