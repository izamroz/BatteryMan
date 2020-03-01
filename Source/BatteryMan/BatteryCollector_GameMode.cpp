// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryCollector_GameMode.h"
#include "GameFramework/Actor.h"

ABatteryCollector_GameMode::ABatteryCollector_GameMode() 
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABatteryCollector_GameMode::BeginPlay() 
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABatteryCollector_GameMode::SpawnPlayerRecharge,
		FMath::RandRange(2, 5), true);
}

void ABatteryCollector_GameMode::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
}

void ABatteryCollector_GameMode::SpawnPlayerRecharge()
{
	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	FVector SpawnPosition = FVector(RandX, RandY, Spawn_Z);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
}
