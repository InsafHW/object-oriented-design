#pragma once
#include <iostream>
#include <functional>

typedef std::function<void()> QuackBehaviorStrategyFunction;

void QuackBehavior()
{
	std::cout << "Quack" << std::endl;
}

void SqueakBehavior()
{
	std::cout << "Squeak" << std::endl;
}

void MuteQuackBehavior()
{
	std::cout << std::endl;
}