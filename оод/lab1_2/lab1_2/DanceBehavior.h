#pragma once
#include <iostream>

struct IDanceBehavior
{
	virtual ~IDanceBehavior() {};
	virtual void Dance() = 0; 
};

class DanceWaltz : public IDanceBehavior
{
public:
	void Dance() override
	{
		std::cout << "I'm dance Waltz!!" << std::endl;
	}
};

class DanceMinuet : public IDanceBehavior
{
public:
	void Dance() override
	{
		std::cout << "I'm dance Minuet!!" << std::endl;
	}
};

class DanceNoWay : public IDanceBehavior
{
public:
	void Dance() override {}
};