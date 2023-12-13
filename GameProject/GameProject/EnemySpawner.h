#pragma once
#include "GameCore.h"
class EnemySpawner : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(EnemySpawner, Component)

	void Update() override;

	float spawntime = 2.0;
public:
	int health = 10;
};

