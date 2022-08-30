#pragma once
#include <memory>
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "DanceBehavior.h"

using namespace std;

class Duck
{
public:
	Duck(
		unique_ptr<IFlyBehavior>&& flyBehavior,
		unique_ptr<IQuackBehavior>&& quackBehavior,
		unique_ptr<IDanceBehavior>&& danceBehavior
	)
	{
		SetFlyBehavior(move(flyBehavior));
		SetDanceBehavior(move(danceBehavior));
		SetQuackBehavior(move(quackBehavior));
	}

	virtual ~Duck() = default;

	virtual void Display() const = 0;

	void Swim() const
	{
		std::cout << "I am swimming" << std::endl;
	}

	void Quack() const
	{
		m_quackBehavior->Quack();
	}

	void Fly() const
	{
		m_flyBehavior->Fly();
	}

	void Dance() const
	{
		m_danceBehavior->Dance();
	}

	void SetFlyBehavior(unique_ptr<IFlyBehavior>&& flyBehavior)
	{
		m_flyBehavior = move(flyBehavior);
	}

	void SetDanceBehavior(unique_ptr<IDanceBehavior>&& danceBehavior)
	{
		m_danceBehavior = move(danceBehavior);
	}

	void SetQuackBehavior(unique_ptr<IQuackBehavior>&& quackBehavior)
	{
		m_quackBehavior = move(quackBehavior);
	}

private:
	unique_ptr<IFlyBehavior> m_flyBehavior;
	unique_ptr<IDanceBehavior> m_danceBehavior;
	unique_ptr<IQuackBehavior> m_quackBehavior;
};


class MallardDuck : public Duck
{
public: 
	MallardDuck()
		:Duck(make_unique<FlyWithWings>(), make_unique<QuackBehavior>(), make_unique<WaltzhDance>())
	{}

	void Display() const override
	{
		std::cout << "I am Mallard duck" << std::endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		:Duck(make_unique<FlyWithWings>(), make_unique<QuackBehavior>(), make_unique<MinuetDance>())
	{}

	void Display() const override
	{
		std::cout << "I am Redhead duck" << std::endl;
	}
};

class DecoyDuck : public Duck
{
public:
	DecoyDuck()
		: Duck(make_unique<FlyNoWay>(), make_unique<MuteQuackBehavior>(), make_unique<DanceNoWay>())
	{}

	void Display() const override
	{
		cout << "I'm Decoy duck" << endl;
	}
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(make_unique<FlyNoWay>(), make_unique<SqueakBehavior>(), make_unique<DanceNoWay>())
	{}

	void Display() const override
	{
		cout << "I'm Rubber duck" << endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(make_unique<FlyNoWay>(), make_unique<QuackBehavior>(), make_unique<DanceNoWay>())
	{}

	void Display() const override
	{
		cout << "I'm Model duck" << endl;
	}
};