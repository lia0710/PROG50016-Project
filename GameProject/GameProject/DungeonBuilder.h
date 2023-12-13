#pragma once
#include "GameCore.h"
class DungeonBuilder : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(DungeonBuilder, Component)
public:
	void Initialize();
	void Load(json::JSON& node);

	std::vector<int> walls;
	std::vector<int> layout;
};

