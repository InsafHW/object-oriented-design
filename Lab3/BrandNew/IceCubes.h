#pragma once
#include "CCondimentDecorator.h"

enum class IceCubeType
{
	Dry,	// Сухой лед (для суровых сибирских мужиков)
	Water	// Обычные кубики из воды
};

// Кубики льда
class CIceCubes: public CCondimentDecorator
{
public:
	CIceCubes(IBeveragePtr&& beverage, unsigned quantity, IceCubeType type = IceCubeType::Water)
		: CCondimentDecorator(std::move(beverage)),
		m_quantity(quantity),
		m_type(type)
	{}
protected:
	double GetCondimentCost() const override
	{
		const auto cubeCost = GetCubeCost();
		return cubeCost * m_quantity;
	}

	std::string GetCondimentDescription() const override
	{
		const auto cubeTypeText = GetCubeTypeText();
		return cubeTypeText + " ice cubes x" + std::to_string(m_quantity);
	}
private:
	unsigned m_quantity;
	IceCubeType m_type;

	double GetCubeCost() const
	{
		return m_type == IceCubeType::Dry ? 10 : 5;
	}

	std::string GetCubeTypeText() const
	{
		return m_type == IceCubeType::Dry ? "Dry" : "Water";
	}
};

