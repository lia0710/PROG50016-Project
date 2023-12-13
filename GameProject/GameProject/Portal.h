#pragma once
#include "GameCore.h"
class Portal : public Component
{
    DECLARE_DYNAMIC_DERIVED_CLASS(Portal, Component)
    BoxCollider* collider = nullptr;
    STRCODE next_scene = -1;
    Vec2 start_pos;

    void Initialize() override;
    void Update() override;
    void Load(json::JSON&) override;
};

