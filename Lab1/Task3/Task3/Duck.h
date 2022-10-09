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
		FlyBehaviorStrategyFunction&& flyBehavior,
		QuackBehaviorStrategyFunction&& quackBehavior,
		DanceBehaviorStrategyFunction&& danceBehavior
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
		m_quackBehavior();
	}

	void Fly() const
	{
		m_flyBehavior();
	}

	void Dance() const
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(FlyBehaviorStrategyFunction&& flyBehavior)
	{
		m_flyBehavior = move(flyBehavior);
	}

	void SetDanceBehavior(DanceBehaviorStrategyFunction&& danceBehavior)
	{
		m_danceBehavior = move(danceBehavior);
	}

	void SetQuackBehavior(QuackBehaviorStrategyFunction&& quackBehavior)
	{
		m_quackBehavior = move(quackBehavior);
	}

private:
	FlyBehaviorStrategyFunction m_flyBehavior;
	DanceBehaviorStrategyFunction m_danceBehavior;
	QuackBehaviorStrategyFunction m_quackBehavior;
};


class MallardDuck : public Duck
{
public:
	MallardDuck()
		:Duck(FlyWithWings, QuackBehavior, WaltzhDance)
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
		:Duck(FlyWithWings, QuackBehavior, MinuetDance)
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
		: Duck(FlyNoWay, MuteQuackBehavior, DanceNoWay)
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
		: Duck(FlyNoWay, SqueakBehavior, DanceNoWay)
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
		: Duck(FlyNoWay, QuackBehavior, DanceNoWay)
	{}

	void Display() const override
	{
		cout << "I'm Model duck" << endl;
	}
};