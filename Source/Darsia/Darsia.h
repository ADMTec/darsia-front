#pragma once

#include "CoreMinimal.h"

#if UE_BUILD_DEVELOPMENT

#define DARSIA_UTILS

DECLARE_LOG_CATEGORY_EXTERN(LogAssert, All, All);

/**
 * Custom assertion that will quit the PIE instance in the next frame if failed
 * The editor may crash if the assertion was required in next lines before the PIE is ended
 * Usage: ASSERTF(x > y, "x=%d was not greater tha y=%d", x, y);
 * Requires that you #include "Kismet/GameplayStatics.h"
 * @param bExpression expression to evaluate
 * @param Message format string to print
 */
#define ASSERTF(bExpression, Message, ...) \
{ \
	if (!(bExpression)) \
	{ \
		FString __du_MessageF = FString::Printf(TEXT(Message ""), ##__VA_ARGS__); \
		UE_LOG(LogAssert, Error, TEXT("[Assertion (" #bExpression ") Failed] %s"), *__du_MessageF); \
		UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false); \
	} \
}

/** Same as ASSERTF but without a message */
#define ASSERT(bExpression) ASSERTF(bExpression, "")

/** Log simplification like GAME_LOG macro from here https://community.gamedev.tv/t/easier-logging-macro/4060 */
#define ulog(Message, ...) \
{ \
	const FString __du_Msg = FString::Printf(TEXT(Message), ##__VA_ARGS__); \
	UE_LOG(LogTemp, Log, TEXT("%s"), *__du_Msg); \
}

/** Log simplification like GAME_LOG macro from here https://community.gamedev.tv/t/easier-logging-macro/4060 */
#define uwarn(Message, ...) \
{ \
	const FString __du_Msg = FString::Printf(TEXT(Message), ##__VA_ARGS__); \
	UE_LOG(LogTemp, Warning, TEXT("%s"), *__du_Msg); \
}

#else // UE_BUILD_DEVELOPMENT

#define ASSERTF(bExpression, Message, ...)
#define ASSERT(bExpression) ASSERTF(bExpression, "")
#define GAME_LOG(Message, ...)

#endif // UE_BUILD_DEVELOPMENT