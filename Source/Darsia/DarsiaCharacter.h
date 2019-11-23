#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DarsiaCharacter.generated.h"

UCLASS()
class DARSIA_API ADarsiaCharacter : public ACharacter
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
