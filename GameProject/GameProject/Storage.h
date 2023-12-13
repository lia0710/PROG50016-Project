#pragma once
#include "GameCore.h"
class Storage
{
public:
	static Storage& Instance()
	{
		if (instance == nullptr)
		{
			instance = new Storage();
		}
		return *instance;
	}



	void AddWall(Entity* wall) { walls.push_back(wall); }
	void RemoveWall(Entity* wall) { walls.remove(wall); }
	void ClearWalls() { walls.clear(); }
	bool IsAWall(Entity* wall);


	void AddEnemy(Entity* enemy) { enemies.push_back(enemy); }
	void RemoveEnemy(Entity* enemy) { enemies.remove(enemy); }
	void ClearEnemy() { enemies.clear(); }
	bool IsAnEnemy(Entity* enemy);


	void AddEnemySpawn(Entity* enemyspawn) { enemySpawns.push_back(enemyspawn); }
	void RemoveEnemySpawn(Entity* enemyspawn) { enemySpawns.remove(enemyspawn); }
	void ClearEnemySpawn() { enemySpawns.clear(); }
	bool IsAnEnemySpawn(Entity* enemyspawn);

	std::list<Entity*> walls;
	std::list<Entity*> enemies;
	std::list<Entity*> enemySpawns;

	int playerhealth = 3;
	float timeLeft = 300.0;
	int enemiesDefeated = 0;

private:
	static Storage* instance;

private:
	inline explicit Storage() = default;
	inline ~Storage() = default;
	inline explicit Storage(Storage const&) = delete;
	inline Storage& operator=(Storage const&) = delete;
};

