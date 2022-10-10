#pragma once
#include <iostream>

struct IFlyBehavior
{
	virtual ~IFlyBehavior() {};
	virtual void Fly() = 0;
	virtual void IncreaseNumberOfFlights() {};
};

class CFlyBehavior: public IFlyBehavior
{
public:
	void IncreaseNumberOfFlights() override
	{
		m_countOfFlight++;
	}
	int GetCountOfFlights() const
	{
		return m_countOfFlight;
	}
private:
	int m_countOfFlight = 0;
};

class FlyWithWings: public CFlyBehavior
{
public:
	void Fly() override
	{
		std::cout << "I'm flying with wings!! This is flight number " << GetCountOfFlights() << std::endl;
	}
};

class FlyNoWay: public CFlyBehavior
{
public:
	void Fly() override {}
};
//как в программе с утками без стратегии сделать так, чтобы подсчет происходил всегда
//как сделать так, чтобы потомки не забывали вызвать 
//ещще подумать