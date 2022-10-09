#pragma once
#include "IBeverage.h"

// Базовый декоратор Добавки для напитка.
class CCondimentDecorator: public IBeverage
{
public:
	std::string GetDescription() const override
	{
		return m_beverage->GetDescription() + ". " + GetCondimentDescription();
	}

	double GetCost() const override
	{
		return m_beverage->GetCost() + GetCondimentCost();
	}

	virtual std::string GetCondimentDescription() const = 0;
	virtual double GetCondimentCost() const = 0;
protected:
	CCondimentDecorator(IBeveragePtr&& beverage)
		:m_beverage(std::move(beverage))
	{}
private:
	IBeveragePtr m_beverage;
};

