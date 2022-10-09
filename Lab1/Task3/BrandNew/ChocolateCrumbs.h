#pragma once
#include "CCondimentDecorator.h"

// ���������� ������
class CChocolateCrumbs: public CCondimentDecorator
{
public:
	CChocolateCrumbs(IBeveragePtr&& beverage, unsigned mass)
		:CCondimentDecorator(std::move(beverage)),
		m_mass(mass)
	{}
protected:
	double GetCondimentCost()const override
	{
		return 2.0 * m_mass;
	}

	std::string GetCondimentDescription()const override
	{
		return "Chocolate crumbs " + std::to_string(m_mass) + "g";
	}
private:
	unsigned m_mass;
};

