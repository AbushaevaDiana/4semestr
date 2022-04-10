#include "CarComands.h"

//
const std::map<Direction, std::string> directionString = {
	{ Direction::Back, "back" },
	{ Direction::Along, "forward" },
	{ Direction::OnPlace, "on place" }
};

const std::map<Gear, std::string> gearString = {
	{ Gear::Reverse, "reverse" },
	{ Gear::Neutral, "neutral" },
	{ Gear::One, "first" },
	{ Gear::Two, "second" },
	{ Gear::Three, "third" },
	{ Gear::Four, "fourth" },
	{ Gear::Five, "fifth" },
};

const std::map<int, Gear> intGear = {
	{ -1, Gear::Reverse },
	{ 0, Gear::Neutral },
	{ 1, Gear::One },
	{ 2, Gear::Two },
	{ 3, Gear::Three },
	{ 4, Gear::Four },
	{ 5, Gear::Five },
};

std::string DirectionToString(Direction direction)
{
	return directionString.at(direction);
}

std::string GearToString(Gear gear)
{
	return gearString.at(gear);
}

bool GetNumberFromStr(std::string inputStr, int& inputNum)
{
	try
	{
		inputNum = stoi(inputStr);
	}
	catch (std::exception& exception)
	{
		std::cout << "Incorrect argument" << std::endl;
		std::cerr << exception.what() << std::endl;
		return false;
	}

	return true;
}

bool GetGearFromArg(std::string inputStr, Gear& gear)
{
	int inputNum = 0;
	if (!GetNumberFromStr(inputStr, inputNum))
	{
		return false;
	}

	if (intGear.find(inputNum) == intGear.end())
	{
		std::cout << "Incorrect gear number" << std::endl;
		return false;
	}

	gear = intGear.at(inputNum);

	return true;
}

bool GetSpeedFromArg(std::string inputStr, int& speed)
{
	if (!GetNumberFromStr(inputStr, speed))
	{
		return false;
	}

	if (speed < 0)
	{
		std::cout << "Incorrect speed number" << std::endl;
		return false;
	}

	return true;
}
//

CarControl::CarControl(Car& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "Info", [this](std::istream& strm) {
			   return Info();
		   } },
		  { "EngineOn", [this](std::istream& strm) {
			   return EngineOn();
		   } },
		  { "EngineOff", [this](std::istream& strm) {
			   return EngineOff();
		   } },
		  { "SetGear", [this](std::istream& strm) {
			   return SetGear(strm);
		   } },
		  { "SetSpeed", [this](std::istream& strm) {
			   return SetSpeed(strm);
		   } },
		})
{
}

bool CarControl::Command()
{
	std::string commandLine;
	getline(m_input, commandLine);
    std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CarControl::Info() const
{
	if (m_car.IsEngineTurnedOn())
	{
		m_output << "Engine: turned on" << std::endl;
	}
	else
	{
		m_output << "Engine: turned off" << std::endl;
	}

	m_output << "Direction: " << DirectionToString(m_car.GetDirection()) << std::endl;
	m_output << "Gear: " << GearToString(m_car.GetGear()) << std::endl;
	m_output << "Speed: " << abs(m_car.GetSpeed()) << std::endl;
	return true;
}

bool CarControl::EngineOn()
{
   if (m_car.TurnOnEngine())
   {
		m_output << "Engine turned on successfully" << std::endl;
   }
   else
   {			   
	   m_output << "Engine is already running" << std::endl;
   }
   return true;
}

bool CarControl::EngineOff()
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine turned off successfully" << std::endl;
	}
	else
	{
		m_output << "Can't turned off the engine" << std::endl;
	}

	return true;
}


bool CarControl::SetGear(std::istream& args)
{
	std::string inpStr;
    args >> inpStr;
    Gear gear = Gear::Neutral;

	if (GetGearFromArg(inpStr, gear))
	{
		if (m_car.SetGear(gear))
	    {
			m_output << GearToString(gear) << " gear is selected" << std::endl;
		}
		else
		{
		    m_output << "Gear didn't change" << std::endl;
		}
	}

	return true;
}


bool CarControl::SetSpeed(std::istream& args)
{
	std::string inpStr;
    args >> inpStr;
    int inSpeed = 0;

    if (GetSpeedFromArg(inpStr, inSpeed))
    {
		if (m_car.SetSpeed(inSpeed))
	    {
			m_output << inSpeed << " speed is selected" << std::endl;
		}
		else
		{
			m_output << "Speed didn't change" << std::endl;
		}
    }

	return true;
}