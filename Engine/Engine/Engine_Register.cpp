#include "EngineCore.h"

#include "Object.h"
#include "Component.h"

void Engine_Register()
{
	REGISTER_TYPECLASS(Object);
	REGISTER_TYPECLASS(Component);
}
