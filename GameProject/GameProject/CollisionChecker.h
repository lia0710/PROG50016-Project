#pragma once
class CollisionChecker
{
public:
	bool check(std::string entityName, Entity* passer);
	bool Portalcheck(std::string entityName, Entity* passer);
	bool checkWall(Entity* passer);
	bool checkSpawner(Entity* passer);
	bool checkEnemy(Entity* passer);
};

