#include "Singleton.h"
#include <iostream>

Singleton* Singleton::uniqueInstance = nullptr;

Singleton* Singleton::getInstance()
{
	if (uniqueInstance == nullptr)
	{
		uniqueInstance = new Singleton();
	}
	return uniqueInstance;
}

void Singleton::showMessage()
{
	std::cout << "I AM SINGLETON" << std::endl;
}

