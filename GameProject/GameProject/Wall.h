#pragma once
#include "GameCore.h"
class Wall : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Wall, Component)

	void Update();
};

