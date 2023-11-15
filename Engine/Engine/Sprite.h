#pragma once

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Component.h"
#include "IRenderable.h"

class Sprite : public Component, IRenderable
{
public:
	Sprite();
	~Sprite();

	const std::string& GetComponentType() override;

protected:
	void Render() override;
};

#endif