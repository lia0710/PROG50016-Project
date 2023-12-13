#pragma once
#include "GameCore.h"
class Projectile : public Component
{
    DECLARE_DYNAMIC_DERIVED_CLASS(Projectile, Component)

    void Initialize() override;
    void Update() override;

public:
    float xmove = 0;
    float ymove = 0;
    float speed = 500;
};

