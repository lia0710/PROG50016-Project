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