#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "GameCore.h"

class Player : public Component
{
    DECLARE_DYNAMIC_DERIVED_CLASS(Player, Component)

public:

    void Initialize() override;
    void Update() override;
    void Load(json::JSON&) override;

    void TakeDamage();

    int health = 3;
private:
    float speed = 5.0f;
    Vec2 start_pos;
    BoxCollider* collider = nullptr;
    STRCODE game_over_scene = -1;

    bool mouseup = false;

    //eventually will be an object pool of projectiles
    Entity* myEntity;
};

#endif // PLAYER_H


