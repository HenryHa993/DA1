// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_FirstPersonProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "FlecsTest/EntityBase.h"

ATP_FirstPersonProjectile::ATP_FirstPersonProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ATP_FirstPersonProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void ATP_FirstPersonProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if(OtherActor != nullptr && (OtherActor != this) && (OtherComp != nullptr))
	{
		AEntityBase* entityBase = Cast<AEntityBase>(OtherActor);
		if(entityBase == nullptr) return;

		flecs::entity entity = entityBase->GetEntity();

		// Add component based on projectile
		// This does not work for some reason.
		switch(ProjectileComponent)
		{
		case EProjectileComponent::ResetComponent:
			entity.remove<XOscillator>();
			entity.remove<YOscillator>();
			entity.remove<ZOscillator>();
			break;
		case EProjectileComponent::XOscillatorComponent:
			entity.add<XOscillator>();
			break;
		case EProjectileComponent::YOscillatorComponent:
			entity.add<YOscillator>();
			break;
		case EProjectileComponent::ZOscillatorComponent:
			entity.add<ZOscillator>();
			break;
		}

		// If all three components given, remove all
		if(entity.has<XOscillator>() && entity.has<YOscillator>() && entity.has<ZOscillator>())
		{
			entity.remove<XOscillator>();
			entity.remove<YOscillator>();
			entity.remove<ZOscillator>();
		}

		// Set colour
		entity.add<SetColour>();
		
		Destroy();
	}
	/*if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}*/
}