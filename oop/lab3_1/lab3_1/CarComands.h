#include "Car.h"
#include <fstream>
#include <map>
#include <functional>
#include <string>
#include <sstream>

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

class CarControl
{
public:
	CarControl(Car& car, std::istream& input, std::ostream& output);
	bool Command();

private:
	bool Info() const;
	bool EngineOn();
	bool EngineOff();

	bool SetGear(std::istream& args); 
	bool SetSpeed(std::istream& args); 

	using Handler = std::function<bool(std::istream& args)>;

	using ActionMap = std::map<std::string, Handler>;

	Car& m_car;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};