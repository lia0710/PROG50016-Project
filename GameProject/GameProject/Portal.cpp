#include "GameCore.h"
#include "Portal.h"

IMPLEMENT_DYNAMIC_CLASS(Portal)


void Portal::Initialize()
{
    start_pos = Vec2(65.625, 634.375);
    collider = (BoxCollider*)ownerEntity->GetComponent("BoxCollider");
}

void Portal::Update()
{
    Scene* current_scene = SceneManager::Get().GetActiveScene();
    CollisionChecker checker;

    if (checker.Portalcheck("Player", ownerEntity))
    {
        //collision effects go here
        if (SceneManager::Get().SetActiveScene(next_scene))
        {
            current_scene->isEnabled = false;
        }
    }
}

void Portal::Load(json::JSON& node)
{
    Component::Load(node);
    if (node.hasKey("NextScene"))
    {
        next_scene = GetHashCode(node.at("NextScene").ToString().c_str());
    }
}