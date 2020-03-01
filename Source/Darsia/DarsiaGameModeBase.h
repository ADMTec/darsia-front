#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DarsiaGameModeBase.generated.h"

UCLASS()
class DARSIA_API ADarsiaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
	void BeginDestroy() override;

	// Character properties

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class ADarsiaCharacter> DarsiaCharacterBP;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	//int NumberOfPlayers = 2;

	// TODO: Using array of BP_DarsiaCharacter's in BP_DarsiaGameMode
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// TArray<class ADarsiaCharacter*> Characters;

	// Middleware initial implementation
	// TODO: Remove CallInEditor specifiers

	TSharedPtr<class FSocketIONative> Socket;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Darsia Middleware")
	void MiddlewareConnect();
};
