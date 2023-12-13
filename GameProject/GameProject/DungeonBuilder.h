#pragma once
#include "GameCore.h"
class DungeonBuilder : public Component
{
	//constructs the level based on the tiled file data
	//reads in the tmf file from json and used that to determine where to place walls and spawners
	DECLARE_DYNAMIC_DERIVED_CLASS(DungeonBuilder, Component)
public:
	void Initialize();
	void Load(json::JSON& node);

	std::vector<int> walls;
	std::vector<int> layout;

	std::vector<int> spawners;
	std::vector<int> spawnlayout;
};

