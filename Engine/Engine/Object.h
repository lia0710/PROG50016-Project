#pragma once

#ifndef _OBJECT_H_
#define _OBJECT_H_

class Object
{
	DECLARE_ABSTRACT_BASE_CLASS(Object)

private:
	bool initialized = false;
	std::string name = "";
	int id = 0;

protected:
	Object();
	virtual ~Object();

public:
	virtual void Initialize() = 0;
	virtual void Destroy() {};

	bool IsInitialize() { return initialized; }
	std::string& GetName() { return name; }
	int GetId() { return id; }
};

#endif // !_OBJECT_H_
