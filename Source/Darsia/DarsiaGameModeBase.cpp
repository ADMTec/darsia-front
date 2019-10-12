#include "DarsiaGameModeBase.h"
#include "DarsiaCharacter.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

void ADarsiaGameModeBase::BeginPlay()
{
	for (int i = 0; i < NumberOfPlayers; i++)
	{
		Characters.Add(GetWorld()->SpawnActor<ADarsiaCharacter>(
			DarsiaCharacterBP, FTransform(FVector(i * 100, 0, 0))
		));
	}
}