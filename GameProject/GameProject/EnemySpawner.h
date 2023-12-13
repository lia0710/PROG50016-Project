#pragma once
#include "GameCore.h"
class EnemySpawner : public Component
{
	//an enemy factory. Creates an enemy at intervals based on spawntime
	//also paired with a collider, and when a projectile hits it the spawn factory's health is reduced
	DECLARE_DYNAMIC_DERIVED_CLASS(EnemySpawner, Component)

	void Update() override;

	float spawntime = 2.0;
public:
	int health = 10;
};

