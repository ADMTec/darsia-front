#include "DarsiaGameModeBase.h"
#include "DarsiaCharacter.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Darsia.h"
#include "SocketIOClient.h"
#include "SocketIONative.h"

void ADarsiaGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//for (int i = 0; i < NumberOfPlayers; i++)
	//{
	//	Characters.Add(GetWorld()->SpawnActor<ADarsiaCharacter>(
	//		DarsiaCharacterBP, FTransform(FVector(i * 200, 0, 0))
	//	));
	//}
}

// Middleware

void ADarsiaGameModeBase::MiddlewareConnect_Implementation() {
	uwarn("Connecting");
	Socket = ISocketIOClientModule::Get().NewValidNativePointer();
	Socket->VerboseLog = true;
	// Socket->Connect("http://192.168.1.100:1337/api/v1/sockets/join", nullptr, nullptr);
	Socket->Connect("https://darsia.herokuapp.com:80");
	// Socket->Connect("http://0.0.0.0:1337");
	Socket->OnEvent(TEXT("goto"), [this](const FString& Event, const TSharedPtr<FJsonValue>& Message) {
		ulog("goto received, load arena info");
		UE_LOG(LogTemp, Log, TEXT("Goto: %s"), *USIOJConvert::ToJsonString(Message));
		Socket->Emit(TEXT("request_map_info"), TEXT("EMPTY_PAYLOAD"));
	});
};

void ADarsiaGameModeBase::BeginDestroy() {
	Super::BeginDestroy();

	// Middleware cleanup
	if (Socket.IsValid()) {
		ISocketIOClientModule::Get().ReleaseNativePointer(Socket);
		Socket = nullptr;
	}
}
