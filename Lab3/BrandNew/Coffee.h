#pragma once
#include "CBeverage.h"

enum class CoffeePortion
{
	Standart,
	Double
};

std::string GetCoffeePortionName(CoffeePortion& portion)
{
	return portion == CoffeePortion::Double ? "Double" : "Standart";
}

class CCoffee: public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		: CBeverage(description)
	{}

	double GetCost() const override
	{
		return 60;
	}
};

class CCapuccino : public CCoffee
{
public: 
	CCapuccino(CoffeePortion portion = CoffeePortion::Standart)
		: CCoffee(GetCoffeePortionName(portion) + " Capuccino"),
		m_portion(portion)
	{}

	double GetCost() const override
	{
		return m_portion == CoffeePortion::Double ? 120 : 80;
	}
private:
	CoffeePortion m_portion;
};

class CLatte :public CCoffee
{
public:
	CLatte(CoffeePortion portion = CoffeePortion::Standart)
		: CCoffee(GetCoffeePortionName(portion) + " Latte"),
		m_portion(portion)
	{}

	double GetCost() const override
	{
		return m_portion == CoffeePortion::Double ? 130 : 90;
	}
private:
	CoffeePortion m_portion;
};