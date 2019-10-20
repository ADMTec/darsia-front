#include "GridMap.h"
#include "Darsia.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

AGridMap::AGridMap()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void AGridMap::OnConstruction(const FTransform & Transform)
{
	for (int i = 0; i < Cells.Num(); i++)
		for (int j = 0; j < Cells[i].Num(); j++)
			Cells[i][j]->DestroyComponent();

	if (!CellDisplayMesh) {
		uwarn("CellDisplayMesh not set on GridMap");
		return;
	}

	Cells.SetNum(Height);
	for (int i = 0; i < Height; i++)
	{
		Cells[i].SetNum(Width);
		for (int j = 0; j < Width; j++)
		{
			UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(
				this,
				UStaticMeshComponent::StaticClass()
			);
			MeshComponent->SetStaticMesh(CellDisplayMesh);
			MeshComponent->SetRelativeLocation(FVector(CellWidth * j, CellHeight * i, 0));
			MeshComponent->RegisterComponent();
			MeshComponent->AttachTo(RootComponent);
			Cells[i][j] = MeshComponent;
		}
	}
}
