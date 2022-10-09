#pragma once
#include <iostream>
#include <functional>

typedef std::function<void()> DanceBehaviorStrategyFunction;

void DanceNoWay()
{
	std::cout << std::endl;
}

void WaltzhDance()
{
	std::cout << "Waltz dance" << std::endl;
}

void MinuetDance()
{
	std::cout << "Minuet dance" << std::endl;
}