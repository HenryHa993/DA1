// Fill out your copyright notice in the Description page of Project Settings.


#include "SystemsModule.h"

#include "ComponentsModule.h"

void USystemsModule::Initialise(flecs::world& ecs)
{
	// If you do not want it registered to a timeline, set kind(0)
	/*flecs::system testSys = ecs.system<Transform>("Test System")
		.each([](Transform& t)
		{
			UE_LOG(LogTemp, Warning, TEXT("Transform %s"), *t.Value.ToString());
		});*/

	ecs.system<ActorPtr, Transform>("Transform System")
		.each([](ActorPtr& actor,  const Transform& transform)
		{
			UE_LOG(LogTemp, Warning, TEXT("Transform system called"));
			actor.Value->SetActorTransform(transform.Value);
		});

	ecs.system<Transform>("Test Movement System")
	.each([](flecs::iter& it, size_t, Transform& transform)
	{
		UE_LOG(LogTemp, Warning, TEXT("Movement system called"));
		FVector translationPoint = transform.Value.GetLocation();
		translationPoint.Z += 100.0f * it.delta_time();
		transform.Value.SetLocation(translationPoint);
	});
}