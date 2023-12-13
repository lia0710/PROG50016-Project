#pragma once
#include "GameCore.h"
class Enemy : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Enemy, Component)

	void Initialize() override;
	void Update() override;

	Entity* player = nullptr;
	float speed = 400.0;
};

