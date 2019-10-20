#include "Darsia.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Darsia, "Darsia" );

#ifdef DARSIA_UTILS
DEFINE_LOG_CATEGORY(LogAssert);
#endif // DARSIA_UTILS