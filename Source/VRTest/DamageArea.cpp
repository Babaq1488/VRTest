#include "DamageArea.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

ADamageArea::ADamageArea()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
}

void ADamageArea::BeginPlay()
{
	Super::BeginPlay();

}

void ADamageArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 24, SphereColor);

	UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), Radius, nullptr, {}, this, nullptr,
										DoFullDamage, ECC_Pawn);
	
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("DamageArea")));

	
}

