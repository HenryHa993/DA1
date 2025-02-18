// Fill out your copyright notice in the Description page of Project Settings.


#include "SystemsModule.h"

#include "ComponentsModule.h"
#include "Kismet/GameplayStatics.h"

void USystemsModule::Initialise(flecs::world& ecs)
{
	// If you do not want it registered to a timeline, set kind(0)
	/*flecs::system testSys = ecs.system<Transform>("Test System")
		.each([](Transform& t)
		{
			UE_LOG(LogTemp, Warning, TEXT("Transform %s"), *t.Value.ToString());
		});*/

	/*ecs.system<Transform>("Test Movement System")
.each([](flecs::iter& it, size_t, Transform& transform)
{
	UE_LOG(LogTemp, Warning, TEXT("Movement system called"));
	FVector translationPoint = transform.Value.GetLocation();
	translationPoint.Z += 100.0f * it.delta_time();
	transform.Value.SetLocation(translationPoint);
});*/

	//
	ecs.system<Pivot, Transform>("Vertical Oscillator System")
		.with<VerticalOscillator>()
		.each([](flecs::iter& it,size_t,  Pivot& pivot, Transform& transform)
		{
			float elapsedTime = it.world().get_info()->world_time_total;
			float sinValue = FMath::Sin(elapsedTime);
			float z = pivot.Value.Z;
			z += sinValue * 100.0f;
			FVector newLocation = transform.Value.GetLocation();
			newLocation.Z = z;
			transform.Value.SetLocation(newLocation);
		});

	ecs.system<Pivot, Transform>("Horizontal Oscillator System")
	.with<HorizontalOscillator>()
	.each([](flecs::iter& it,size_t,  Pivot& pivot, Transform& transform)
	{
		float elapsedTime = it.world().get_info()->world_time_total;
		float sinValue = FMath::Sin(elapsedTime);
		float x = pivot.Value.X;
		x += sinValue * 100.0f;
		FVector newLocation = transform.Value.GetLocation();
		newLocation.X = x;
		transform.Value.SetLocation(newLocation);
	});
	
	// Update transform of actor
	ecs.system<OwningActor, Transform>("Copy Transform System")
		.each([](OwningActor& actor,  const Transform& transform)
		{
			UE_LOG(LogTemp, Warning, TEXT("Transform system called"));
			actor.Value->SetActorTransform(transform.Value);
		});
}
