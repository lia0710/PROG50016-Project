#include "GameCore.h"
#include "Player.h"

#define NDEBUG_PLAYER

IMPLEMENT_DYNAMIC_CLASS(Player)

void Player::Initialize()
{
    Component::Initialize();
    start_pos = ownerEntity->GetTransform().position;
    collider = (BoxCollider*)ownerEntity->GetComponent("BoxCollider");
}
void Player::Update() {
    health = Storage::Instance().playerhealth;
    Asset* myimage = AssetManager::Get().GetAsset("heart3");
    if (health == 2)
    {
        myimage = AssetManager::Get().GetAsset("heart2");
    }
    else if (health == 1)
    {
        myimage = AssetManager::Get().GetAsset("heart1");
    }

    Entity* ui = nullptr;
    for (const auto& search : SceneManager::Get().FindEntityByName("UIHealth01"))
    {
        ui = search;
    }
    Component* uicomp = ui->GetComponent("Sprite");
    Sprite* mysprite = (Sprite*)(uicomp);
    mysprite->SetTextureAsset(((TextureAsset*)(myimage)));




    Storage::Instance().timeLeft -= Time::Instance().DeltaTime();
    float timeforstring = Storage::Instance().timeLeft;
    std::string timetext = "Time: " + std::to_string(timeforstring);

    Entity* timeui = nullptr;
    for (const auto& search : SceneManager::Get().FindEntityByName("UITime01"))
    {
        timeui = search;
    }
    Component* timeuicomp = timeui->GetComponent("FontSprite");
    FontSprite* mytimesprite = (FontSprite*)(timeuicomp);
    mytimesprite->SetText(timetext);





    int scoreforstring = Storage::Instance().enemiesDefeated;
    std::string scoretext = "Score: " + std::to_string(scoreforstring);

    Entity* scoreui = nullptr;
    for (const auto& search : SceneManager::Get().FindEntityByName("UIScore01"))
    {
        scoreui = search;
    }
    Component* scoreuicomp = scoreui->GetComponent("FontSprite");
    FontSprite* myscoresprite = (FontSprite*)(scoreuicomp);
    myscoresprite->SetText(scoretext);




    Vec2 dir = Vec2::Zero;
    const InputSystem& input = InputSystem::Instance();

    if (!input.isMouseButtonPressed(SDL_BUTTON_LEFT))
    {
        mouseup = true;
    }

    if (input.isMouseButtonPressed(SDL_BUTTON_LEFT) && mouseup) {
        mouseup = false;
        int x, y;
        SDL_GetMouseState(&x, &y);

        Entity* myent = SceneManager::Get().CreateEntity();
        Asset* myimage = AssetManager::Get().GetAsset("abat");
        Component* mycomp = myent->CreateComponent("Sprite");
        Sprite* mysprite = (Sprite*)(mycomp);
        mysprite->SetTextureAsset(((TextureAsset*)(myimage)));
        Projectile* myproj = ((Projectile*)myent->CreateComponent("Projectile"));

        //set transform and destination
        myent->GetTransform().position = Vec2(ownerEntity->GetTransform().position.x, ownerEntity->GetTransform().position.y);

        float xdiff = x - ownerEntity->GetTransform().position.x;
        float ydiff = y - ownerEntity->GetTransform().position.y;

        float theta = atanf(xdiff / ydiff);

        float xmove = sin(theta);
        float ymove = cos(theta);

        if (y <= ownerEntity->GetTransform().position.y)
        {
            xmove *= -1;
            ymove *= -1;
        }

        myproj->xmove = xmove;
        myproj->ymove = ymove;
    }

    if (input.isKeyPressed(SDLK_q) && mouseup) {

        Entity* myent = SceneManager::Get().CreateEntity();
        Asset* myimage = AssetManager::Get().GetAsset("abat");
        Component* mycomp = myent->CreateComponent("Sprite");
        Sprite* mysprite = (Sprite*)(mycomp);
        mysprite->SetTextureAsset(((TextureAsset*)(myimage)));
    }

    // Handle horizontal movement
    if (input.isKeyPressed(SDLK_LEFT) || input.isKeyPressed(SDLK_a) || input.isGamepadButtonPressed(0, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) {
        dir.x -= 1;
    }
    if (input.isKeyPressed(SDLK_RIGHT) || input.isKeyPressed(SDLK_d) || input.isGamepadButtonPressed(0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) {
        dir.x += 1;
    }

    // Handle vertical movement
    if (input.isKeyPressed(SDLK_UP) || input.isKeyPressed(SDLK_w) || input.isGamepadButtonPressed(0, SDL_CONTROLLER_BUTTON_DPAD_UP)) {
        dir.y -= 1;
    }
    if (input.isKeyPressed(SDLK_DOWN) || input.isKeyPressed(SDLK_s) || input.isGamepadButtonPressed(0, SDL_CONTROLLER_BUTTON_DPAD_DOWN)) {
        dir.y += 1;
    }

    // Handle gamepad analog stick input
    if (dir == Vec2::Zero) {
        dir.x = input.getGamepadAxisState(0, SDL_CONTROLLER_AXIS_LEFTX);
        dir.y = input.getGamepadAxisState(0, SDL_CONTROLLER_AXIS_LEFTY);
    }

    // Normalize the direction vector if it's not zero
    if (dir != Vec2::Zero) {
        dir.Normalize();
#ifdef DEBUG_PLAYER
        LOG("Input: " << dir.x << ", " << dir.y);
#endif
    }
    // Move the player
    Vec2 old = ownerEntity->GetTransform().position;
        
    ownerEntity->GetTransform().position += dir * (speed * Time::Instance().DeltaTime());

    CollisionChecker checker;

    if (collider == nullptr)
    {
        LOG("no collider uwu");
        return;
    }
}
void Player::Load(json::JSON& node)
{
    Component::Load(node);
    if (node.hasKey("Speed"))
    {
        speed = static_cast<float>(node.at("Speed").ToFloat());
    }

    if (node.hasKey("DeathScene"))
    {
	    game_over_scene = GetHashCode(node.at("DeathScene").ToString().c_str());
    }
}

void Player::TakeDamage()
{
    health -= 1;
    Storage::Instance().playerhealth -= 1;
    if (health <= 0)
    {
        health = 3;
        Storage::Instance().playerhealth = 3;
    }
}
