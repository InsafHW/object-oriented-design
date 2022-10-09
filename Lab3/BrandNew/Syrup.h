#pragma once
#include "CCondimentDecorator.h"

enum class SyrupType
{
	Chocolate,	// Шоколадный
	Maple,		// Кленовый
};

// Сироп
class CSyrup: public CCondimentDecorator
{
public:
	CSyrup(IBeveragePtr&& beverage, SyrupType syrupType)
		: CCondimentDecorator(std::move(beverage)),
		m_type(syrupType)
	{}
protected:
	double GetCondimentCost() const override
	{
		return 15;
	}

	std::string GetCondimentDescription() const override
	{
		const auto syrupTypeText = GetSyrupTypeText();
		return syrupTypeText + " syrup";
	}
private:
	SyrupType m_type;
	std::string GetSyrupTypeText() const
	{
		return m_type == SyrupType::Chocolate ? "Chocolate" : "Maple";
	}
};

