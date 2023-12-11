#pragma once

#ifndef MOUSEFINDER_H
#define MOUSEFINDER_H

#include "GameCore.h"
#include "Sprite.h"

class MouseFinder : public Component
{
    DECLARE_DYNAMIC_DERIVED_CLASS(MouseFinder, Component)

public:
    void Initialize() override;
    void Update() override;
    BoxCollider* collider = nullptr;
    STRCODE next_scene = -1;
};

#endif