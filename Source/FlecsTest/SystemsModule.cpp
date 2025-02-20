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

	// Colour
	ecs.system<StaticMeshComponent, PaintColours>("Blank Colour System")
		.kind(flecs::OnUpdate)
		.with<SetColour>()
		.without<XOscillator>()
		.without<YOscillator>()
		.without<ZOscillator>()
		.each([](StaticMeshComponent& mesh, PaintColours& colours)
	{
		mesh.Value->SetMaterial(0, colours.Value[0]);
	});

	ecs.system<StaticMeshComponent, PaintColours>("Red Colour System")
		.kind(flecs::OnUpdate)
		.with<SetColour>()
		.with<XOscillator>()
		.without<YOscillator>()
		.without<ZOscillator>()
		.each([](StaticMeshComponent& mesh,  PaintColours& colours)
	{
		mesh.Value->SetMaterial(0, colours.Value[1]);
	});

	ecs.system<StaticMeshComponent, PaintColours>("Green Colour System")
		.kind(flecs::OnUpdate)
		.with<SetColour>()
		.with<YOscillator>()
		.without<XOscillator>()
		.without<ZOscillator>()
		.each([](StaticMeshComponent& mesh, PaintColours& colours)
	{
		mesh.Value->SetMaterial(0, colours.Value[2]);
	});

	ecs.system<StaticMeshComponent, PaintColours>("Blue Colour System")
		.kind(flecs::OnUpdate)
		.with<SetColour>()
		.with<ZOscillator>()
		.without<XOscillator>()
		.without<YOscillator>()
		.each([](StaticMeshComponent& mesh, PaintColours& colours)
	{
		mesh.Value->SetMaterial(0, colours.Value[3]);
	});

	ecs.system<StaticMeshComponent, PaintColours>("Yellow Colour System")
		.kind(flecs::OnUpdate)
		.with<SetColour>()
		.with<XOscillator>()
		.with<YOscillator>()
		.without<ZOscillator>()
		.each([](StaticMeshComponent& mesh, PaintColours& colours)
	{
		mesh.Value->SetMaterial(0, colours.Value[4]);
	});

	ecs.system<StaticMeshComponent, PaintColours>("Purple Colour System")
		.kind(flecs::OnUpdate)
		.with<SetColour>()
		.with<XOscillator>()
		.with<ZOscillator>()
		.without<YOscillator>()
		.each([](StaticMeshComponent& mesh, PaintColours& colours)
	{
		mesh.Value->SetMaterial(0, colours.Value[5]);
	});

	ecs.system<StaticMeshComponent, PaintColours>("Cyan Colour System")
		.kind(flecs::OnUpdate)
		.with<SetColour>()
		.with<YOscillator>()
		.with<ZOscillator>()
		.without<XOscillator>()
		.each([](StaticMeshComponent& mesh, PaintColours& colours)
	{
		mesh.Value->SetMaterial(0, colours.Value[6]);
	});

	ecs.system<>("Reset Colour System")
		.kind(flecs::PostUpdate)
		.with<SetColour>()
		.each([](flecs::iter& it, size_t t)
	{
		flecs::entity entity = it.entity(t);
		entity.remove<SetColour>();
	});
	
	//
	ecs.system<Pivot, Transform>("Z Oscillator System")
		.kind(flecs::OnUpdate)
		.with<ZOscillator>()
		.each([](flecs::iter& it,size_t,  Pivot& pivot, Transform& transform)
		{
			float elapsedTime = it.world().get_info()->world_time_total;
			float sinValue = FMath::Sin(elapsedTime * 0.75f);
			float z = pivot.Value.Z;
			z += sinValue * 100.0f;
			FVector newLocation = transform.Value.GetLocation();
			newLocation.Z = z;
			transform.Value.SetLocation(newLocation);
		});

	ecs.system<Pivot, Transform>("X Oscillator System")
		.kind(flecs::OnUpdate)
		.with<XOscillator>()
		.each([](flecs::iter& it,size_t,  Pivot& pivot, Transform& transform)
	{
		float elapsedTime = it.world().get_info()->world_time_total;
		float sinValue = FMath::Sin(elapsedTime * 0.75f);
		float x = pivot.Value.X;
		x += sinValue * 100.0f;
		FVector newLocation = transform.Value.GetLocation();
		newLocation.X = x;
		transform.Value.SetLocation(newLocation);
	});

	ecs.system<Pivot, Transform>("Y Oscillator System")
		.kind(flecs::OnUpdate)
		.with<YOscillator>()
		.each([](flecs::iter& it,size_t,  Pivot& pivot, Transform& transform)
		{
			float elapsedTime = it.world().get_info()->world_time_total;
			float sinValue = FMath::Sin(elapsedTime * 0.75f);
			float y = pivot.Value.Y;
			y += sinValue * 100.0f;
			FVector newLocation = transform.Value.GetLocation();
			newLocation.Y = y;
			transform.Value.SetLocation(newLocation);
		});
	
	// Update transform of actor
	ecs.system<OwningActor, Transform>("Copy Transform System")
		.kind(flecs::PostUpdate)
		.each([](flecs::iter& it, size_t, OwningActor& actor,  const Transform& transform)
		{
			UE_LOG(LogTemp, Warning, TEXT("Transform system called"));
			FVector lerpLocation = FMath::Lerp(actor.Value->GetActorLocation(), transform.Value.GetLocation(), it.delta_time());
			actor.Value->SetActorTransform(transform.Value);
		});
}
