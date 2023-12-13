#pragma once
#include "GameCore.h"
class Wall : public Component
{
	//An interface class, used to represent where a wall is in the map layout
	//Must always have a box collider on the same entity
	DECLARE_DYNAMIC_DERIVED_CLASS(Wall, Component)
};