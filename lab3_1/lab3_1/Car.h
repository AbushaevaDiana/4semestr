#include <iostream>

enum class Gear
{
	Reverse = -1,
	Neutral = 0,
	One = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5
};

enum class Direction
{
	Along,
	Back,
	OnPlace
};

const std::pair<int, int> reverseSpeedLimits = { -20, 0 };
const std::pair<int, int> oneSpeedLimits = { 0, 30 };
const std::pair<int, int> twoSpeedLimits = { 20, 50 };
const std::pair<int, int> threeSpeedLimits = { 30, 60 };
const std::pair<int, int> fourSpeedLimits = { 40, 90 };
const std::pair<int, int> fiveSpeedLimits = { 50, 150 };

class Car
{
public:
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool IsEngineTurnedOn() const;
	bool SetGear(Gear gear); 
	Gear GetGear() const;
	bool SetSpeed(int moduleSpeed);
	int GetSpeed() const;
	Direction GetDirection() const; 

private:
	int car_speed = 0;
	Gear car_gear = Gear::Neutral;
	bool car_isEngineTurnedOn = false;
};