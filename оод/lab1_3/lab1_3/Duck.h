#pragma once
#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "DanceBehavior.h"

typedef std::function<void()> Action;

class Duck
{
public:
	Duck(Action flyBehavior,
		Action quackBehavior,
		Action danceBehavior)
	{
		SetFlyBehavior(flyBehavior);
		SetQuackBehavior(quackBehavior);
		SetDanceBehavior(danceBehavior);
	}
	void Quack() const
	{
		m_quackBehavior();
	}
	void Swim()
	{
		std::cout << "I'm swimming" << std::endl;
	}
	void Fly()
	{
		m_flyBehavior();
	}
	virtual void Dance()
	{
		m_danceBehavior();
	}
	void SetFlyBehavior(Action flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	}
	void SetQuackBehavior(Action quackBehavior)
	{
		m_quackBehavior = quackBehavior;
	}
	void SetDanceBehavior(Action danceBehavior)
	{
		m_danceBehavior = danceBehavior;
	}
	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	Action m_flyBehavior;
	Action m_quackBehavior;
	Action m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		:Duck(FlyWithWings, QuackBehavior, DanceWaltz)
	{
	}

	void Display() const override
	{
		std::cout << "I'm mallard duck" << std::endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		:Duck(FlyWithWings, QuackBehavior, DanceMinuet)
	{
	}
	void Display() const override
	{
		std::cout << "I'm redhead duck" << std::endl;
	}
};

class DecoyDuck : public Duck
{
public:
	DecoyDuck()
		:Duck(FlyNoWay, MuteQuackBehavior, DanceNoWay)
	{
	}
	void Display() const override
	{
		std::cout << "I'm decoy duck" << std::endl;
	}
	void Dance() override {}
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
		:Duck(FlyNoWay, SqueakBehavior, DanceNoWay)
	{
	}
	void Display() const override
	{
		std::cout << "I'm rubber duck" << std::endl;
	}
	void Dance() override {}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		:Duck(FlyNoWay, QuackBehavior, DanceNoWay)
	{
	}
	void Display() const override
	{
		std::cout << "I'm model duck" << std::endl;
	}
	void Dance() override {}
};

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

//реализовать вывод количество вылетов у уток которые умеют летать