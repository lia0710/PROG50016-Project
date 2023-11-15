#pragma once

#include "Object.h"

#include <list>

class Component;

class Entity final : public Object
{
private:
	std::list<Component*> components;

public:
	Entity();
	~Entity();

	void Initialize() override;
	void Update();
	void Destroy() override;

	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);
};

