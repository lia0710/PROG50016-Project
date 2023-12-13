#pragma once
#include "GameCore.h"
class Projectile : public Component
{
    //a projectile shot by the enemy
    //a component attached to an object that causes it to move in a particular direction
    //it gets its direction when created by the player
    DECLARE_DYNAMIC_DERIVED_CLASS(Projectile, Component)

    void Initialize() override;
    void Update() override;

public:
    float xmove = 0;
    float ymove = 0;
    float speed = 500;
};

