#include "GameCore.h"
#include "EnemySpawner.h"
IMPLEMENT_DYNAMIC_CLASS(EnemySpawner)

void EnemySpawner::Update()
{
    spawntime -= Time::Instance().DeltaTime();
    if (spawntime <= 0)
    {
        Entity* myent = SceneManager::Get().CreateEntity();
        Asset* myimage = AssetManager::Get().GetAsset("abat");
        Component* mycomp = myent->CreateComponent("Sprite");
        Sprite* mysprite = (Sprite*)(mycomp);
        mysprite->SetTextureAsset(((TextureAsset*)(myimage)));
        myent->CreateComponent("Enemy");

        //set transform and destination
        myent->GetTransform().position = Vec2(ownerEntity->GetTransform().position.x, ownerEntity->GetTransform().position.y);

        spawntime = 5.0;
    }
}