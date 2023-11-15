#include "EngineCore.h"
#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

const std::string& Sprite::GetComponentType()
{
	static std::string _spriteClass = "Sprite";
	return _spriteClass;
}

void Sprite::Render()
{
	// RENDER CODE HERE
}
