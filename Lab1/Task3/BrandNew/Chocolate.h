#pragma once
#include "CCondimentDecorator.h"

// Шоколад
class CChocolate: public CCondimentDecorator
{
public:
	CChocolate(IBeveragePtr&& beverage, unsigned quantity = 1)
		: CCondimentDecorator(std::move(beverage))
	{
		if (quantity > MAX_QUANTITY)
		{
			throw "Max chocolate count is " + MAX_QUANTITY;
		}
		m_quantity = quantity;
	}
protected:
	double GetCondimentCost() const override
	{
		return 10 * m_quantity;
	}

	std::string GetCondimentDescription() const override
	{
		return "Chocolate x" + std::to_string(m_quantity);
	}
private:
	const unsigned MAX_QUANTITY = 5;
	unsigned m_quantity;
};

