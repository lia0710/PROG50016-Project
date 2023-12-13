#pragma once

#ifndef MOUSEFINDER_H
#define MOUSEFINDER_H

#include "GameCore.h"
#include "Sprite.h"

class MouseFinder : public Component
{
    //a utility for the mouse in the menu
    //it has an attached collider that moves to the mouse's position on a click
    //this collider checks for collision with a button and moves the scene forward to start the game
    DECLARE_DYNAMIC_DERIVED_CLASS(MouseFinder, Component)

public:
    void Initialize() override;
    void Update() override;
    void Load(json::JSON&) override;
    BoxCollider* collider = nullptr;
    STRCODE next_scene = -1;
};

#endif