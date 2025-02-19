// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TP_FirstPersonProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UENUM(BlueprintType)
enum class EProjectileComponent : uint8
{
	ResetComponent,
	XOscillatorComponent,
	YOscillatorComponent,
	ZOscillatorComponent
};

UCLASS(config=Game)
class ATP_FirstPersonProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileMechanic)
	TArray<UMaterial*> PaintMaterials;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileMechanic)
	EProjectileComponent ProjectileComponent;

public:
	ATP_FirstPersonProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

