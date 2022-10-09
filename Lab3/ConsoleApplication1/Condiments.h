#pragma once

#include "IBeverage.h"
#include <stdexcept>

// ���������� ���������� IBeverage

// ������� ��������� "������� � �������". ����� �������� ��������
class CCondimentDecorator : public IBeverage
{
public:
	std::string GetDescription()const override
	{
		// �������� ��������������� ������� ����������� � �������� �������������� �������
		return m_beverage->GetDescription() + ", " + GetCondimentDescription();
	}

	double GetCost()const override
	{
		// ��������� ������������ �� ��������� ������� � ��������� ������������� �������
		return m_beverage->GetCost() + GetCondimentCost();
	}

	// ��������� � �������� ������� ����������� � ������� ���������� �����������
	virtual std::string GetCondimentDescription()const = 0;
	virtual double GetCondimentCost()const = 0;
protected:
	CCondimentDecorator(IBeveragePtr&& beverage)
		: m_beverage(move(beverage))
	{}
private:
	IBeveragePtr m_beverage;
};

// ������� �� ������
class CCinnamon : public CCondimentDecorator
{
public:
	CCinnamon(IBeveragePtr&& beverage)
		: CCondimentDecorator(move(beverage))
	{}
protected:
	double GetCondimentCost()const override
	{
		return 20;
	}

	std::string GetCondimentDescription()const override
	{
		return "Cinnamon";
	}
};

// �������� �������
class CLemon : public CCondimentDecorator
{
public:
	CLemon(IBeveragePtr&& beverage, unsigned quantity = 1)
		: CCondimentDecorator(move(beverage))
		, m_quantity(quantity)
	{}
protected:
	double GetCondimentCost()const override
	{
		return 10.0 * m_quantity;
	}
	std::string GetCondimentDescription()const override
	{
		return "Lemon x " + std::to_string(m_quantity);
	}
private:
	unsigned m_quantity;
};


enum class IceCubeType
{
	Dry,	// ����� ��� (��� ������� ��������� �������)
	Water	// ������� ������ �� ����
};

// ������� "������ ����". ������������ ����� � ����������� �������, ��� ������ �� ���������
// � ��������
class CIceCubes : public CCondimentDecorator
{
public:
	CIceCubes(IBeveragePtr&& beverage, unsigned quantity, IceCubeType type = IceCubeType::Water)
		: CCondimentDecorator(move(beverage))
		, m_quantity(quantity)
		, m_type(type)
	{}
protected:
	double GetCondimentCost()const override
	{
		// ��� ������ �������, ��� ������ ���������.
		// ����� ��� ����� ������
		return (m_type == IceCubeType::Dry ? 10 : 5) * m_quantity;
	}
	std::string GetCondimentDescription()const override
	{
		return std::string(m_type == IceCubeType::Dry ? "Dry" : "Water")
			+ " ice cubes x " + std::to_string(m_quantity);
	}
private:
	unsigned m_quantity;
	IceCubeType m_type;
};

// ��� ������
enum class SyrupType
{
	Chocolate,	// ����������
	Maple,		// ��������
};

// ������� "�����"
class CSyrup : public CCondimentDecorator
{
public:
	CSyrup(IBeveragePtr&& beverage, SyrupType syrupType)
		: CCondimentDecorator(move(beverage))
		, m_syrupType(syrupType)
	{}
protected:
	double GetCondimentCost()const override
	{
		return 15;
	}
	std::string GetCondimentDescription()const override
	{
		return std::string(m_syrupType == SyrupType::Chocolate ? "Chocolate" : "Maple")
			+ " syrup";
	}
private:
	SyrupType m_syrupType;
};

// ���������� ������
class CChocolateCrumbs : public CCondimentDecorator
{
public:
	CChocolateCrumbs(IBeveragePtr&& beverage, unsigned mass)
		:CCondimentDecorator(move(beverage))
		, m_mass(mass)
	{
	}

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

// ��������� �������
class CCoconutFlakes : public CCondimentDecorator
{
public:
	CCoconutFlakes(IBeveragePtr&& beverage, unsigned mass)
		: CCondimentDecorator(move(beverage))
		, m_mass(mass)
	{}

protected:
	double GetCondimentCost() const override
	{
		return 1.0 * m_mass;
	}
	std::string GetCondimentDescription()const override
	{
		return "Coconut flakes " + std::to_string(m_mass) + "g";
	}
private:
	unsigned m_mass;
};

class CCream : public CCondimentDecorator
{
public: CCream(IBeveragePtr&& beverage)
		: CCondimentDecorator(move(beverage))
	{}
protected:
	double GetCondimentCost() const override
	{
		return 25;
	}
	std::string GetCondimentDescription()const override
	{
		return "Cream";
	}
};

class CChocolate : public CCondimentDecorator
{
public: CChocolate(IBeveragePtr&& beverage, int slicesCount)
	: CCondimentDecorator(move(beverage))
	{
		if (slicesCount > 5)
		{
			throw std::invalid_argument("Max slices count for chocolate is 5");
		}
		m_count = slicesCount;
	}
protected:
	double GetCondimentCost() const override
	{
		return 10.0 * m_count;
	}
	std::string GetCondimentDescription()const override
	{
		return "Chocolate. Slices:" + m_count;
	}
private:
	int m_count;
};

enum class LiquirType
{
	Nutty,
	�hocolate
};

class CLiquor : public CCondimentDecorator
{
public: CLiquor(IBeveragePtr&& beverage, const LiquirType& liquirType)
	: CCondimentDecorator(move(beverage))
		, m_type(liquirType)
	{}
protected:
	double GetCondimentCost() const override
	{
		return 50;
	}
	std::string GetCondimentDescription()const override
	{
		std::string type = m_type == LiquirType::Nutty ? "Nutty" : "Chocolate";
		return "Liquir. Type:" + type;
	}
private:
	LiquirType m_type;
};