#pragma once
class CollisionChecker
{
public:
	bool check(std::string entityName, Entity* passer);
	bool Portalcheck(std::string entityName, Entity* passer);
};

