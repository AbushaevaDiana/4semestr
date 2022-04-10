#include "Car.h"
#include <fstream>
#include <map>
#include <functional>
#include <string>
#include <sstream>

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