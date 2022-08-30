#pragma once
#include <iostream>

struct IQuackBehavior
{
	virtual void Quack() = 0;
	virtual ~IQuackBehavior() {};
};

class QuackBehavior : public IQuackBehavior {
	void Quack() override 
	{
		std::cout << "Quack" << std::endl;
	}
};

class SqueakBehavior : public IQuackBehavior {
	void Quack() override 
	{
		std::cout << "Squeak" << std::endl;
	}
};

class MuteQuackBehavior : public IQuackBehavior {
	void Quack() override 
	{
		std::cout << std::endl;
	}
};