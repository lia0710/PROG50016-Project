#pragma once
#include "GameCore.h"
class Portal : public Component
{
    //a component that's paired with a box collider and a sprite
    //when the player collides with this, it moves to the next scene
    DECLARE_DYNAMIC_DERIVED_CLASS(Portal, Component)
    BoxCollider* collider = nullptr;
    STRCODE next_scene = -1;
    Vec2 start_pos;

    void Initialize() override;
    void Update() override;
    void Load(json::JSON&) override;
};

