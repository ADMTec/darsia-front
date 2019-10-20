#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridMap.generated.h"

UCLASS()
class DARSIA_API AGridMap : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AGridMap();

	void OnConstruction(const FTransform& Transform) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMesh* CellDisplayMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Width = 5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Height = 5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CellWidth = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CellHeight = 100;

	TArray<TArray<class UStaticMeshComponent*>> Cells;

};
