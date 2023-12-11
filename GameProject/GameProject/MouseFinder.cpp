#include "GameCore.h"
#include "MouseFinder.h"

IMPLEMENT_DYNAMIC_CLASS(MouseFinder)

void MouseFinder::Initialize()
{
    collider = (BoxCollider*)ownerEntity->GetComponent("BoxCollider");
}
void MouseFinder::Update() 
{
    const InputSystem& input = InputSystem::Instance();
    if (input.isMouseButtonPressed(SDL_BUTTON_LEFT)) {
        int x, y;
        SDL_GetMouseState(&x, &y);

        ownerEntity->GetTransform().position.x = x;
        ownerEntity->GetTransform().position.y = y;

        const CollisionSystem& collisionsys = CollisionSystem::Instance();
        BoxCollider* other = nullptr;
        for (const auto& otherfind : collisionsys.colliders)
        {
            if (otherfind->GetOwner()->GetName() != "Button")
            {
                continue;
            }

            other = static_cast<BoxCollider*>(otherfind);
        }

        if (other != nullptr)
        {
            SDL_Rect* collidersquare = nullptr;
            if (ownerEntity->HasComponent("Sprite"))
            {
                collidersquare = &((Sprite*)(ownerEntity->GetComponent("Sprite")))->targetRect;
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
                    LOG("Collision")
                }
            }

        }

        for (const auto& other : collider->OnCollisionEnter())
        {
            if (other->GetOwner()->GetName() != "Button")
            {
                continue;
            }


            Scene* current_scene = SceneManager::Get().GetActiveScene();
            if (SceneManager::Get().SetActiveScene(next_scene))
            {
                current_scene->isEnabled = false;
            }
        }
    }
}