#include "GameCore.h"
#include "Storage.h"

Storage* Storage::instance = nullptr;

bool Storage::IsAWall(Entity* wall)
{
    for (const auto& search : walls)
    {
        if (wall == search)
        {
            return true;
        }
    }
    return false;
}

bool Storage::IsAnEnemy(Entity* enemy)
{
    for (const auto& search : enemies)
    {
        if (enemy == search)
        {
            return true;
        }
    }
    return false;
}

bool Storage::IsAnEnemySpawn(Entity* enemyspawn)
{
    for (const auto& search : enemySpawns)
    {
        if (enemyspawn == search)
        {
            return true;
        }
    }
    return false;
}