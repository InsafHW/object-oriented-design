#pragma once
#include "CCondimentDecorator.h"

// ������
class CCream: public CCondimentDecorator
{
public:
	CCream(IBeveragePtr&& beverage)
		:CCondimentDecorator(std::move(beverage))
	{}
protected:
	double GetCondimentCost() const override
	{
		return 25;
	}

	std::string GetCondimentDescription() const override
	{
		return "Cream";
	}
};

