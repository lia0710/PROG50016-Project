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

bool CollisionChecker::checkWall(Entity* passer)
{
    const CollisionSystem& collisionsys = CollisionSystem::Instance();
    BoxCollider* other = nullptr;
    for (const auto& otherfind : collisionsys.colliders)
    {
        if (Storage::Instance().IsAWall(otherfind->GetOwner()) && otherfind->GetOwner()->GetParentScene() == SceneManager::Get().GetActiveScene())
        {
            other = static_cast<BoxCollider*>(otherfind);
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
                        Vec2 total = Vec2((passer->GetTransform().position.x - other->GetOwner()->GetTransform().position.x), (passer->GetTransform().position.y - other->GetOwner()->GetTransform().position.y));
                            
                        
                        if (total.x > 0 && total.x < othersquare->w)
                            {
                                passer->GetTransform().position.x += othersquare->w - total.x;
                            }
                            else if (total.x < 0 && other->GetOwner()->GetTransform().position.x < collidersquare->w + passer->GetTransform().position.x)
                            {
                                passer->GetTransform().position.x -= othersquare->w + total.x;
                            }
                            else if (total.y > 0 && total.y < othersquare->h)
                            {
                                //player below, wall above
                                passer->GetTransform().position.y += othersquare->h - total.y;
                            }
                            else if (total.y < 0 && other->GetOwner()->GetTransform().position.y < collidersquare->h + passer->GetTransform().position.y)
                            {
                                //player above, wall below
                                passer->GetTransform().position.y -= othersquare->h + total.y;
                            }
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

bool CollisionChecker::checkSpawner(Entity* passer)
{
    const CollisionSystem& collisionsys = CollisionSystem::Instance();
    BoxCollider* other = nullptr;
    for (const auto& otherfind : collisionsys.colliders)
    {
        if (Storage::Instance().IsAnEnemySpawn(otherfind->GetOwner()) && otherfind->GetOwner()->GetParentScene() == SceneManager::Get().GetActiveScene())
        {
            other = static_cast<BoxCollider*>(otherfind);
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
                        ((EnemySpawner*)other->GetOwner()->GetComponent("EnemySpawner"))->health -= 1;
                        if (((EnemySpawner*)other->GetOwner()->GetComponent("EnemySpawner"))->health <= 0)
                        {
                            SceneManager::Get().RemoveEntity(other->GetOwner()->GetGuid());
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool CollisionChecker::checkEnemy(Entity* passer)
{
    const CollisionSystem& collisionsys = CollisionSystem::Instance();
    BoxCollider* other = nullptr;
    for (const auto& otherfind : collisionsys.colliders)
    {
        if (Storage::Instance().IsAnEnemy(otherfind->GetOwner()) && otherfind->GetOwner()->GetParentScene() == SceneManager::Get().GetActiveScene())
        {
            other = static_cast<BoxCollider*>(otherfind);
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
                        ((Enemy*)other->GetOwner()->GetComponent("Enemy"))->health -= 1;
                        if (((Enemy*)other->GetOwner()->GetComponent("Enemy"))->health <= 0)
                        {
                            Storage::Instance().enemiesDefeated += 1;
                            SceneManager::Get().RemoveEntity(other->GetOwner()->GetGuid());
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}