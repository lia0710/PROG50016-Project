#include "GameCore.h"
#include "CollisionChecker.h"

bool CollisionChecker::check(std::string entityName, Entity* passer)
{
    const CollisionSystem& collisionsys = CollisionSystem::Instance();
    BoxCollider* other = nullptr;
    for (const auto& otherfind : collisionsys.colliders)
    {
        //ownerscene
        if (otherfind->GetOwner()->GetName() != entityName || otherfind->GetOwner()->GetParentScene() != SceneManager::Get().GetActiveScene())
        {
            continue;
        }
        other = static_cast<BoxCollider*>(otherfind);
    }

    if (other != nullptr)
    {
        SDL_Rect* collidersquare = nullptr;
        if (passer->HasComponent("Sprite"))
        {
            collidersquare = &((Sprite*)(passer->GetComponent("Sprite")))->targetRect;
        }
        SDL_Rect* othersquare = nullptr;
        if (other->GetOwner()->HasComponent("Sprite"))
        {
            othersquare = &((Sprite*)(other->GetOwner()->GetComponent("Sprite")))->targetRect;
        }
        if (collidersquare != nullptr && othersquare != nullptr)
        {
            if (SDL_HasIntersection(collidersquare, othersquare))
            {
                return true;
            }
        }

    }
    return false;
}

bool CollisionChecker::Portalcheck(std::string entityName, Entity* passer)
{
    const CollisionSystem& collisionsys = CollisionSystem::Instance();
    BoxCollider* other = nullptr;
    for (const auto& otherfind : collisionsys.colliders)
    {
        //ownerscene
        if (otherfind->GetOwner()->GetName() != entityName || otherfind->GetOwner()->GetParentScene() != SceneManager::Get().GetActiveScene())
        {
            continue;
        }
        other = static_cast<BoxCollider*>(otherfind);
    }

    if (other != nullptr)
    {
        SDL_Rect* collidersquare = nullptr;
        if (passer->HasComponent("Sprite"))
        {
            collidersquare = &((Sprite*)(passer->GetComponent("Sprite")))->targetRect;
        }
        SDL_Rect* othersquare = nullptr;
        if (other->GetOwner()->HasComponent("Sprite"))
        {
            othersquare = &((Sprite*)(other->GetOwner()->GetComponent("Sprite")))->targetRect;
        }
        if (collidersquare != nullptr && othersquare != nullptr)
        {
            if (SDL_HasIntersection(collidersquare, othersquare))
            {
                other->GetOwner()->GetTransform().position = Vec2(65.625, 634.375);
                return true;
            }
        }
    }
    return false;
}