#include "GameCore.h"

void GameRegisterClasses()
{
	REGISTER_TYPECLASS(Player);
	REGISTER_TYPECLASS(GameOver);
	REGISTER_TYPECLASS(MouseFinder);
	REGISTER_TYPECLASS(Portal);
	REGISTER_TYPECLASS(DungeonBuilder);
	REGISTER_TYPECLASS(Wall);
	REGISTER_TYPECLASS(Projectile);
}