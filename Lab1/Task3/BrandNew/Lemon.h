#pragma once
#include "CCondimentDecorator.h"

// Лимон
class CLemon: public CCondimentDecorator
{
public:
	CLemon(IBeveragePtr&& beverage, unsigned quantity = 1)
		: CCondimentDecorator(std::move(beverage)),
		m_quantity(quantity)
	{}
protected:
	double GetCondimentCost() const override
	{
		return m_pieceCost * m_quantity;
	}

	std::string GetCondimentDescription() const override
	{
		return "Lemon x " + std::to_string(m_quantity);
	}
private:
	double const m_pieceCost = 10;
	unsigned m_quantity;
};

