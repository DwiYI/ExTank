// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh Component"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast Component"));
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast Component"));
	LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Componenet"));
	ProjectileMovement->bAutoActivate = false;

	ForceExplosion = CreateDefaultSubobject<URadialForceComponent>(FName("Force Explosion Componenet"));
	ForceExplosion->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
}

void AProjectile::LaunchProjectile(float speed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	ProjectileMovement->Activate();
}

void AProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	LaunchBlast->Deactivate();
	ImpactBlast->Activate();
	ForceExplosion->FireImpulse();
	SetRootComponent(ImpactBlast);
	CollisionMesh->DestroyComponent();
	UGameplayStatics::ApplyRadialDamage(this, HitDamage, GetActorLocation(), ForceExplosion->Radius,UDamageType::StaticClass(), TArray<AActor*>());
	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AProjectile::OnTimerDestroy, TimerDelay, false);
}

void AProjectile::OnTimerDestroy()
{
	Destroy();
}

