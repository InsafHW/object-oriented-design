#pragma once
#include <iostream>

struct IDanceBehavior
{
	virtual void Dance() = 0;
	virtual ~IDanceBehavior() {};
};

class DanceNoWay : public IDanceBehavior {
	void Dance() override 
	{
		std::cout << std::endl;
	};
};

class WaltzhDance : public IDanceBehavior {
	void Dance() override
	{
		std::cout << "Waltz dance" << std::endl;
	}
};

class MinuetDance : public IDanceBehavior {
	void Dance() override
	{
		std::cout << "Minuet dance" << std::endl;
	}
};