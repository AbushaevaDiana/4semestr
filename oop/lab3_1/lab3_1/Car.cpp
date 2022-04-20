#include "Car.h"

bool IsGearInSpeedFrames(Gear gear, int m_speed)
{
	if (gear == Gear::Reverse && m_speed == 0)
	{
		return true;
	}
	if (gear == Gear::Neutral)
	{
		return true;
	}
	if (gear == Gear::One && m_speed >= oneSpeedLimits.first && m_speed <= oneSpeedLimits.second)
	{
		return true;
	}
	if (gear == Gear::Two && m_speed >= twoSpeedLimits.first && m_speed <= twoSpeedLimits.second)
	{
		return true;
	}
	if (gear == Gear::Three && m_speed >= threeSpeedLimits.first && m_speed <= threeSpeedLimits.second)
	{
		return true;
	}
	if (gear == Gear::Four && m_speed >= fourSpeedLimits.first && m_speed <= fourSpeedLimits.second)
	{
		return true;
	}
	if (gear == Gear::Five && m_speed >= fiveSpeedLimits.first && m_speed <= fiveSpeedLimits.second)
	{
		return true;
	}

	return false;
}

//TODO: не понятная функция
bool Car::IsCorrectGearForThisSpeed(int in_speed, Direction direction)
{
	switch (m_gear)
	{
	case Gear::Neutral:
		switch (direction)
		{
		case Direction::Back:
			return (in_speed >= m_speed && in_speed <= 0);
		case Direction::Along:
			return (in_speed <= m_speed && in_speed >= 0);
		default:
			return false;
		}

	case Gear::Reverse:
		return (in_speed >= reverseSpeedLimits.first && in_speed <= reverseSpeedLimits.second);

	default:
		return (IsGearInSpeedFrames(m_gear, in_speed));
	}

	return false;
}
//дополнительные функции

bool Car::TurnOffEngine()
{
	if (m_isEngineTurnedOn && (m_gear == Gear::Neutral) && (m_speed == 0))
	{
		m_isEngineTurnedOn = false;
		return true;
	}
	return false;
}

bool Car::TurnOnEngine()
{
	if (!m_isEngineTurnedOn)
	{
		m_isEngineTurnedOn = true;
		return true;
	}
	return false;
}

bool Car::IsEngineTurnedOn() const
{
	return m_isEngineTurnedOn;
}


bool Car::SetGear(Gear gear)
{
	if (m_isEngineTurnedOn && IsGearInSpeedFrames(gear, m_speed))
	{
		m_gear = gear;
		return true;
	}
	return false;
}

Gear Car::GetGear() const
{
	return m_gear;
}

bool Car::SetSpeed(int moduleSpeed)
{
	int speed = moduleSpeed;
	//TODO: const negativeIndex лучше просто убрать +
	Direction direction = Car::GetDirection();

	if (speed < 0)
	{
		return false;
	}

	if (direction == Direction::Back || (direction == Direction::OnPlace && m_gear == Gear::Reverse))
	{
		speed = -speed;
	}

	if (m_isEngineTurnedOn && IsCorrectGearForThisSpeed(speed, direction))
	{
		m_speed = speed;
		return true;
	}
	return false;
}

//TODO: может вернуть отрицательно значение, так не должно быть +
int Car::GetSpeed() const
{
	if (m_speed < 0)
	{
		return -m_speed;
	}
	return m_speed;
}

Direction Car::GetDirection() const
{
	if (m_speed < 0)
	{
		return Direction::Back;
	}
	if (m_speed > 0)
	{
		return Direction::Along;
	}
	return Direction::OnPlace;
}




