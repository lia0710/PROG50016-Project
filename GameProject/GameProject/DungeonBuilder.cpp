#include "GameCore.h"
#include "DungeonBuilder.h"

IMPLEMENT_DYNAMIC_CLASS(DungeonBuilder)

void DungeonBuilder::Initialize()
{
	for (int i = 0; i < layout.size(); i++)
	{
		for (int j = 0; j < walls.size(); j++)
		{
			if (walls[j] == layout[i])
			{
				//build
				Entity* myent = SceneManager::Get().CreateEntity();
				myent->CreateComponent("BoxCollider");
				Asset* myimage = AssetManager::Get().GetAsset("hiddenSquare");
				Component* mycomp = myent->CreateComponent("Sprite");
				Sprite* mysprite = (Sprite*)(mycomp);
				mysprite->SetTextureAsset(((TextureAsset*)(myimage)));
				myent->CreateComponent("Wall");
				//now set transform
				int x = i % 16;
				float xf = 43.75 * x + 21.875;
				int y = i / 16;
				float yf = 43.75 * y + 21.875;
				myent->GetTransform().position = Vec2(xf, yf);
				Storage::Instance().AddWall(myent);
			}
		}
	}

	for (int i = 0; i < spawnlayout.size(); i++)
	{
		for (int j = 0; j < spawners.size(); j++)
		{
			if (spawners[j] == spawnlayout[i])
			{
				//build
				Entity* myent = SceneManager::Get().CreateEntity();
				myent->CreateComponent("BoxCollider");
				Asset* myimage = AssetManager::Get().GetAsset("hiddenSquare");
				Component* mycomp = myent->CreateComponent("Sprite");
				Sprite* mysprite = (Sprite*)(mycomp);
				mysprite->SetTextureAsset(((TextureAsset*)(myimage)));
				myent->CreateComponent("Wall");
				myent->CreateComponent("EnemySpawner");
				//now set transform
				int x = i % 16;
				float xf = 43.75 * x + (2*21.875);
				int y = i / 16;
				float yf = 43.75 * y + (2 * 21.875);
				myent->GetTransform().position = Vec2(xf, yf);
				myent->GetTransform().scale = Vec2(2.0, 2.0);
				Storage::Instance().AddWall(myent);
			}
		}
	}
}

void DungeonBuilder::Load(json::JSON& node)
{
	Component::Load(node);
	if (node.hasKey("Walls"))
	{
		int i = 0;
		json::JSON jwalls = node["Walls"];

		for (json::JSON& wallint : jwalls.ArrayRange())
		{
			walls.push_back(wallint.ToInt());
			i++;
		}
	}

	if (node.hasKey("Layout"))
	{
		int i = 0;
		json::JSON jlayout = node["Layout"];

		for (json::JSON& layoutint : jlayout.ArrayRange())
		{
			layout.push_back(layoutint.ToInt());
			i++;
		}
	}

	if (node.hasKey("Spawners"))
	{
		int i = 0;
		json::JSON jspawn = node["Spawners"];

		for (json::JSON& spawnint : jspawn.ArrayRange())
		{
			spawners.push_back(spawnint.ToInt());
			i++;
		}
	}

	if (node.hasKey("SpawnLayout"))
	{
		int i = 0;
		json::JSON jlayout = node["SpawnLayout"];

		for (json::JSON& layoutint : jlayout.ArrayRange())
		{
			spawnlayout.push_back(layoutint.ToInt());
			i++;
		}
	}
}