#include "GameCore.h"
#include "Enemy.h"
IMPLEMENT_DYNAMIC_CLASS(Enemy)

void Enemy::Initialize()
{
    for (const auto& playerfind : SceneManager::Get().FindEntityWithComponent("Player"))
    {
        //ownerscene
        if (playerfind->GetParentScene() != SceneManager::Get().GetActiveScene())
        {
            continue;
        }
        player = playerfind;
    }
}
void Enemy::Update()
{
    float dirx = 0;
    float diry = 0;

    if (player != nullptr)
    {
        if (ownerEntity->GetTransform().position.x < player->GetTransform().position.x)
        {
            dirx += 1;
        }
        else if (ownerEntity->GetTransform().position.x > player->GetTransform().position.x)
        {
            dirx -= 1;
        }

        if (ownerEntity->GetTransform().position.y < player->GetTransform().position.y)
        {
            diry += 1;
        }
        else if (ownerEntity->GetTransform().position.y > player->GetTransform().position.y)
        {
            diry -= 1;
        }

        Vec2 dir = Vec2(dirx, diry);

        if (dir != Vec2::Zero) 
        {
            dir.Normalize();
        }

        ownerEntity->GetTransform().position += dir * (speed * Time::Instance().DeltaTime());

        CollisionChecker checker;

        if (checker.Portalcheck("Player", ownerEntity))
        {
            //collision effects go here
            SceneManager::Get().RemoveEntity(ownerEntity->GetGuid());
            ((Player*)player->GetComponent("Player"))->TakeDamage();
        }
    }
}