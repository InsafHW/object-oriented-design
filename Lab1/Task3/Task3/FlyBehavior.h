#pragma once
#include <iostream>
#include <functional>

typedef std::function<void()> FlyBehaviorStrategyFunction;

void FlyNoWay()
{
	std::cout << std::endl;
}

std::function<void> FlyWithWings()
{
    int count = 0;
    auto x = [count]() mutable {
        count++;
        std::cout << "Fly with wings " << count << " times" << std::endl;
    };
    return x;
}