#include "EngineCore.h"
#include "Entity.h"
#include "Component.h"

#include <iostream>

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Initialize()
{
}

void Entity::Update()
{
	for (auto component : components)
	{
		component->Update();
	}
}

void Entity::Destroy()
{
	std::cout << "Entity is Destroyed" << std::endl;
	for (auto component : components)
	{
		delete component;
	}
	components.clear();
}

void Entity::AddComponent(Component* _component)
{
	components.push_back(_component);
}

void Entity::RemoveComponent(Component* _component)
{
	components.remove(_component);
}
