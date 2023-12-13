#pragma once
#include "GameCore.h"
class Enemy : public Component
{
	//a component that makes a sprite move towards the player
	//when the collider on its entity is hit by a projectile, its health is reduced. Destroyed at 0 health
	//if it collides with the player, it reduces player hp by 1
	DECLARE_DYNAMIC_DERIVED_CLASS(Enemy, Component)

	void Initialize() override;
	void Update() override;

	Entity* player = nullptr;
	float speed = 100.0;
public:
	int health = 3;
};

