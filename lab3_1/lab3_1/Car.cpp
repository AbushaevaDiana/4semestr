#include "Car.h"

//дополнительные функции
bool IsGearInSpeedFrames(Gear gear, int car_speed)
{
	if (gear == Gear::Reverse && car_speed == 0)
	{
		return true;
	}
	if (gear == Gear::Neutral)
	{
		return true;
	}
	if (gear == Gear::One && car_speed >= oneSpeedLimits.first && car_speed <= oneSpeedLimits.second)
	{
		return true;
	}
	if (gear == Gear::Two && car_speed >= twoSpeedLimits.first && car_speed <= twoSpeedLimits.second)
	{
		return true;
	}
	if (gear == Gear::Three && car_speed >= threeSpeedLimits.first && car_speed <= threeSpeedLimits.second)
	{
		return true;
	}
	if (gear == Gear::Four && car_speed >= fourSpeedLimits.first && car_speed <= fourSpeedLimits.second)
	{
		return true;
	}
	if (gear == Gear::Five && car_speed >= fiveSpeedLimits.first && car_speed <= fiveSpeedLimits.second)
	{
		return true;
	}

	return false;
}

bool IsCorrectGear(Gear car_gear, int in_speed, int car_speed, Direction direction)
{
	switch (car_gear)
	{
	case Gear::Neutral:
		switch (direction)
		{
		case Direction::Back:
			return (in_speed >= car_speed && in_speed <= 0);
		case Direction::Along:
			return (in_speed <= car_speed && in_speed >= 0);
		default:
			return false;
		}

	case Gear::Reverse:
		return (in_speed >= reverseSpeedLimits.first && in_speed <= reverseSpeedLimits.second);

	default:
		return (IsGearInSpeedFrames(car_gear, in_speed));
	}

	return false;
}
//дополнительные функции

bool Car::TurnOffEngine()
{
	if (car_isEngineTurnedOn && (car_gear == Gear::Neutral) && (car_speed == 0))
	{
		car_isEngineTurnedOn = false;
		return true;
	}
	return false;
}

bool Car::TurnOnEngine()
{
	if (!car_isEngineTurnedOn)
	{
		car_isEngineTurnedOn = true;
		return true;
	}
	return false;
}

bool Car::IsEngineTurnedOn() const
{
	return car_isEngineTurnedOn;
}


bool Car::SetGear(Gear gear)
{
	if (car_isEngineTurnedOn && IsGearInSpeedFrames(gear, car_speed))
	{
		car_gear = gear;
		return true;
	}
	return false;
}

Gear Car::GetGear() const
{
	return car_gear;
}

bool Car::SetSpeed(int moduleSpeed)
{
	int speed = moduleSpeed;
	int negativeIndex = -1;
	Direction direction = Car::GetDirection();

	if (speed < 0)
	{
		return false;
	}

	if (direction == Direction::Back || (direction == Direction::OnPlace && car_gear == Gear::Reverse))
	{
		speed = speed * negativeIndex;
	}

	if (car_isEngineTurnedOn && IsCorrectGear(car_gear, speed, car_speed, direction))
	{
		car_speed = speed;
		return true;
	}
	return false;
}


int Car::GetSpeed() const
{
	return car_speed;
}

Direction Car::GetDirection() const
{
	if (car_speed < 0)
	{
		return Direction::Back;
	}
	if (car_speed > 0)
	{
		return Direction::Along;
	}
	return Direction::OnPlace;
}




