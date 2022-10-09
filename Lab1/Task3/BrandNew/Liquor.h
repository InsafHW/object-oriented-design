#pragma once
#include "CCondimentDecorator.h"

enum class LiquorType
{
	Nutty,
	Chocolate
};

std::string GetLiquorTypeName(LiquorType type)
{
	return type == LiquorType::Chocolate ? "Chocolate" : "Nutty";
}

class CLiquor: public CCondimentDecorator
{
public:
	CLiquor(IBeveragePtr&& beverage, LiquorType type)
		: CCondimentDecorator(std::move(beverage)),
		m_type(type)
	{}
protected:
	double GetCondimentCost() const override
	{
		return 50;
	}

	std::string GetCondimentDescription() const override
	{
		const auto liquorTypeName = GetLiquorTypeName(m_type);
		return liquorTypeName + " liquor";
	}
private:
	LiquorType m_type;
};

