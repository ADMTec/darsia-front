#include "DarsiaCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ADarsiaCharacter::ADarsiaCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	//DisplayMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DisplayMesh"));

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Darsia/Grid/S_Cell.S_Cell"));
	//if (MeshAsset.Succeeded())
	//{
	//	DisplayMesh->SetStaticMesh(MeshAsset.Object);
	//}
	//RootComponent = DisplayMesh;
}

void ADarsiaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADarsiaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

