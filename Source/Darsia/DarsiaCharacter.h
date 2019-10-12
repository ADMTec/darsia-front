#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DarsiaCharacter.generated.h"

UCLASS()
class DARSIA_API ADarsiaCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	ADarsiaCharacter();
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* DisplayMesh;

	virtual void BeginPlay() override;
};
