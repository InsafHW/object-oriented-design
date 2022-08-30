#pragma once
#include <iostream>

struct IFlyBehavior
{
	virtual void Fly() = 0;
	virtual ~IFlyBehavior() {};

};

class FlyNoWay : public IFlyBehavior {
	void Fly() override 
	{
		std::cout << std::endl;
	}
};

class FlyWithWings : public IFlyBehavior {
	void Fly() override 
	{
		std::cout << "Fly with wings " << ++m_count << " times" << std::endl;
	}

	int GetFliesCount()
	{
		return m_count;
	}
private:
	int m_count = 0;
};