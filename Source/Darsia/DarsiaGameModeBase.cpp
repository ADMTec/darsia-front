#include "DarsiaGameModeBase.h"
#include "DarsiaCharacter.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Darsia.h"

void ADarsiaGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ulog("FARAFAAA");
	//for (int i = 0; i < NumberOfPlayers; i++)
	//{
	//	Characters.Add(GetWorld()->SpawnActor<ADarsiaCharacter>(
	//		DarsiaCharacterBP, FTransform(FVector(i * 200, 0, 0))
	//	));
	//}
}