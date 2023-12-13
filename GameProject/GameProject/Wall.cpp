#include "GameCore.h"
#include "Wall.h"
IMPLEMENT_DYNAMIC_CLASS(Wall)

void Wall::Update()
{
	//LOG(static_cast<BoxCollider*>(ownerEntity->GetComponent("BoxCollider"))->attached)
	CollisionChecker checker;
	if (checker.check("Player", ownerEntity))
	{
		//LOG("Collision")
	}
}