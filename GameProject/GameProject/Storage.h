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

private:
	static Storage* instance;
	std::list<Entity*> walls;

private:
	inline explicit Storage() = default;
	inline ~Storage() = default;
	inline explicit Storage(Storage const&) = delete;
	inline Storage& operator=(Storage const&) = delete;
};

