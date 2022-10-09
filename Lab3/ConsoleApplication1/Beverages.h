#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string& description)
		:m_description(description)
	{}

	std::string GetDescription() const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

enum class CoffeeSize
{
	Default,
	Double
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const CoffeeSize& coffeeSize, const std::string& description = "Coffee")
		:CBeverage(description + ". Size: " + GetSizeDescription(coffeeSize)),
		m_size(coffeeSize)
	{}

	double GetCost() const override
	{
		return 60;
	}

	CoffeeSize GetCoffeeSize() const
	{
		return m_size;
	}
private:
	CoffeeSize m_size;
	std::string GetSizeDescription(const CoffeeSize& size)
	{
		switch (size)
		{
		case CoffeeSize::Default:
			return "Default";
		case CoffeeSize::Double:
			return "Double";
		default:
			return "";
		}
	}
};

// Капуччино
class CCappuccino : public CCoffee
{
public:
	CCappuccino(const CoffeeSize& coffeeSize)
		:CCoffee(coffeeSize, "Cappuccino")
	{}

	double GetCost() const override
	{
		return 80;
	}
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(const CoffeeSize& coffeeSize)
		:CCoffee(coffeeSize, "Latte")
	{}

	double GetCost() const override
	{
		return GetCoffeeSize() == CoffeeSize::Double ? 130 : 90;
	}
};

enum class TeaType
{
	Ulun,
	Black,
	Green,
	Red
};

// Чай
class CTea : public CBeverage
{
public:
	CTea(const TeaType& teaType)
		:CBeverage("Tea. Type:" + GetTeaTypeDescription(teaType))
		, m_type(teaType)
	{}

	double GetCost() const override
	{
		return 30;
	}
private:
	TeaType m_type;
	std::string GetTeaTypeDescription(const TeaType& type)
	{
		switch (type)
		{
		case TeaType::Ulun:
			return "Ulun";
		case TeaType::Black:
			return "Black";
		case TeaType::Green:
			return "Green";
		case TeaType::Red:
			return "Red";
		default:
			return "";
		}
	}
};

enum class MilkShakeSize
{
	Small,
	Middle,
	Large
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(const MilkShakeSize& milkShakeSize)
		:CBeverage("Milkshake"),
		m_size(milkShakeSize)
	{}

	double GetCost() const override
	{
		switch (m_size)
		{
		case MilkShakeSize::Small:
			return 50;
		case MilkShakeSize::Middle:
			return 60;
		case MilkShakeSize::Large:
			return 80;
		default:
			return 60;
		}
	}
private:
	MilkShakeSize m_size;
};
