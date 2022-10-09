#pragma once
#include <iostream>
#include <functional>

typedef std::function<void()> FlyBehaviorStrategyFunction;

void FlyNoWay()
{
	std::cout << std::endl;
}

void FlyWithWings()
{
	std::cout << "Fly with wings " << std::endl;
}