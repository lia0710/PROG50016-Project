#pragma once
class CollisionChecker
{
	//a class to help with collision detection
	//in each function, passer should be the one calling the function
	//check returns true if the caller is colliding with an entity with a certain name
	//Portalcheck works the same, is intended for the portal to call on the player, and resets player to starting position for when they next play this level
	//checkWall determines if the passer is colliding with a Wall
	//checkSpawner determines if the passer is colliding with a Spawner
	//checkEnemy determines if the passer is colliding with an Enemy
public:
	bool check(std::string entityName, Entity* passer);
	bool Portalcheck(std::string entityName, Entity* passer);
	bool checkWall(Entity* passer);
	bool checkSpawner(Entity* passer);
	bool checkEnemy(Entity* passer);
};

