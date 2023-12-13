#include "GameCore.h"
#include "Projectile.h"

IMPLEMENT_DYNAMIC_CLASS(Projectile)


void Projectile::Initialize()
{

}
void Projectile::Update()
{
	ownerEntity->GetTransform().position.x += xmove * (speed * Time::Instance().DeltaTime());
	ownerEntity->GetTransform().position.y += ymove * (speed * Time::Instance().DeltaTime());


	CollisionChecker checker;
	if (checker.checkWall(ownerEntity))
	{
		SceneManager::Get().RemoveEntity(ownerEntity->GetGuid());
	}
}