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
    auto fn = []() mutable
    {
        int count = 0;
        auto innerFn = [count]() mutable
        {
            count++;
        };
        innerFn();
        std::cout << "Fly with wings " << count << " times" << std::endl;
    };
    fn();
}