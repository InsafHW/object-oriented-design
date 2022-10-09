#pragma once
#include "CBeverage.h"

enum class MilkshakePortion
{
	Small,
	Medium,
	Large
};

std::string GetMilshakePortionName(MilkshakePortion& portion)
{
	switch (portion)
	{
	case MilkshakePortion::Large:
		return "Large";
	case MilkshakePortion::Medium:
		return "Medium";
	case MilkshakePortion::Small:
		return "Small";
	default:
		throw "Unknown milkshake portion type";
	}
}

class CMilkshake: public CBeverage
{
public:
	CMilkshake(MilkshakePortion portion)
		: CBeverage(GetMilshakePortionName(portion) + " Milkshake"),
		m_portion(portion)
	{}

	double GetCost() const override
	{
		switch (m_portion)
		{
		case MilkshakePortion::Small:
			return 50;
		case MilkshakePortion::Medium:
			return 60;
		case MilkshakePortion::Large:
			return 80;
		default:
			throw "Unknown milkshake portion type";
		}
	}
private:
	MilkshakePortion m_portion;
};