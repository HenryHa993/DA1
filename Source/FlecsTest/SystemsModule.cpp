// Fill out your copyright notice in the Description page of Project Settings.


#include "SystemsModule.h"

#include "ComponentsModule.h"
#include "Kismet/GameplayStatics.h"

void USystemsModule::Initialise(flecs::world& ecs)
{
	// Update timer
	ecs.system<Timer>("Timer System")
		.kind(flecs::PreUpdate)
		.with<XOscillator>().oper(flecs::Or)
		.with<YOscillator>().oper(flecs::Or)
		.with<ZOscillator>()
		.each([](flecs::iter& it,size_t index, Timer& timer)
		{
			timer.Value += it.delta_time();
			//UE_LOG(LogTemp, Warning, TEXT("Timer: %f"), timer.Value);
		});

	
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
	
	// Oscillators
	ecs.system<Timer, LocalTransform, OscillationSpeed, OscillationDistance>("X Oscillator System")
		.kind(flecs::OnUpdate)
		.with<XOscillator>()
		.each([](Timer& timer, LocalTransform& localTransform, OscillationSpeed& speed, OscillationDistance& distance)
	{
		float sinValue = FMath::Sin(timer.Value * speed.Value);
		float x = sinValue * distance.Value;
		FVector newLocation = localTransform.Value.GetLocation();
		newLocation.X = x;
		localTransform.Value.SetLocation(newLocation);
	});

	ecs.system<Timer, LocalTransform, OscillationSpeed, OscillationDistance>("Y Oscillator System")
		.kind(flecs::OnUpdate)
		.with<YOscillator>()
		.each([](Timer& timer, LocalTransform& localTransform, OscillationSpeed& speed, OscillationDistance& distance)
		{
			float sinValue = FMath::Sin(timer.Value * speed.Value);
			float y = sinValue * distance.Value;
			FVector newLocation = localTransform.Value.GetLocation();
			newLocation.Y = y;
			localTransform.Value.SetLocation(newLocation);
		});

	ecs.system<Timer, LocalTransform, OscillationSpeed, OscillationDistance>("Z Oscillator System")
		.kind(flecs::OnUpdate)
		.with<ZOscillator>()
		.each([](Timer& timer, LocalTransform& localTransform, OscillationSpeed& speed, OscillationDistance& distance)
		{
			float sinValue = FMath::Sin(timer.Value * speed.Value);
			float z = sinValue * distance.Value;
			FVector newLocation = localTransform.Value.GetLocation();
			newLocation.Z = z;
			localTransform.Value.SetLocation(newLocation);
		});
	
	// Update transform of actor
	// I don't think I will use this one just yet
	/*ecs.system<OwningActor, Transform>("Copy Transform System")
		.kind(flecs::PostUpdate)
		.each([](flecs::iter& it, size_t, OwningActor& actor,  const Transform& transform)
		{
			UE_LOG(LogTemp, Warning, TEXT("Transform system called"));
			FVector lerpLocation = FMath::Lerp(actor.Value->GetActorLocation(), transform.Value.GetLocation(), it.delta_time());
			actor.Value->SetActorTransform(transform.Value);
		});*/

	ecs.system<StaticMeshComponent, LocalTransform>("Copy Local Transform System")
		.kind(flecs::PostUpdate)
		.each([](flecs::iter& it, size_t, StaticMeshComponent& mesh,  const LocalTransform& localTransform)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Transform system called"));
			FTransform blendedTransform;
			blendedTransform.Blend(mesh.Value->GetRelativeTransform(), localTransform.Value, it.delta_time() * 2);
			mesh.Value->SetRelativeTransform(blendedTransform);
		});
}
