#include "EngineCore.h"
#include "Object.h"

IMPLEMENT_ABSTRACT_CLASS(Object)

Object::Object()
{
	std::cout << "Object is Created" << std::endl;
}

Object::~Object()
{
	std::cout << "Object is Destroyed" << std::endl;
}

//void Object::Initialize()
//{
//	std::cout << "Object is Initialized" << std::endl;
//}
