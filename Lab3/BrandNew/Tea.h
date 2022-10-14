#pragma once
#include "CBeverage.h"

enum class TeaType
{
	Black,
	White,
	Ulun,
	Puer
};

inline std::string GetTeaTypeName(TeaType& type)
{
	switch (type)
	{
	case TeaType::Black:
		return "Black";
	case TeaType::White:
		return "White";
	case TeaType::Ulun:
		return "Ulun";
	case TeaType::Puer:
		return "Puer";
	default:
		throw std::invalid_argument("Unknown tea type");
	}
}

class CTea: public CBeverage
{
public:
	CTea(TeaType type)
		: CBeverage(GetTeaTypeName(type) + " Tea"),
		m_type(type)
	{}

	double GetCost() const override
	{
		return 30;
	}
private:
	TeaType m_type;
};