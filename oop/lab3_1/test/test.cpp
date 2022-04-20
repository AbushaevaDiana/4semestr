#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab3_1/CarComands.h"

TEST_CASE("Car")
{
	SECTION("Object creation")
	{
		Car car;
		REQUIRE(car.IsEngineTurnedOn() == false);
		REQUIRE(car.GetDirection() == Direction::OnPlace);
		REQUIRE(car.GetGear() == Gear::Neutral);
		REQUIRE(car.GetSpeed() == 0);
	}

	SECTION("The state of the car does't change when the engine is turned off")
	{
		Car car;
		REQUIRE(car.IsEngineTurnedOn() == false);

		REQUIRE(car.SetGear(Gear::One) == false);
		REQUIRE(car.SetGear(Gear::Reverse) == false);
		REQUIRE(car.SetGear(Gear::Neutral) == false);

		REQUIRE(car.SetSpeed(10) == false);
		REQUIRE(car.SetSpeed(0) == false);
	}

	SECTION("Turning on/off engine on place")
	{
		Car car;
		REQUIRE(car.TurnOnEngine() == true);
		REQUIRE(car.IsEngineTurnedOn() == true);
		REQUIRE(car.TurnOffEngine() == true);
		REQUIRE(car.IsEngineTurnedOn() == false);
	}

	SECTION("Changing gear on place with turning on engine")
	{
		Car car;
		REQUIRE(car.TurnOnEngine() == true);

		REQUIRE(car.SetGear(Gear::One) == true);
		REQUIRE(car.SetGear(Gear::Reverse) == true);
		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetGear(Gear::Two) == false);
	}

	SECTION("Changing speed")
	{
		Car car;
		REQUIRE(car.TurnOnEngine() == true);

		REQUIRE(car.SetGear(Gear::One) == true);

		REQUIRE(car.SetSpeed(10) == true);
		REQUIRE(car.SetSpeed(20) == true);
		REQUIRE(car.SetSpeed(30) == true);
	}

	SECTION("Changing speed and gear; check speed limits")
	{
		Car car;
		REQUIRE(car.TurnOnEngine() == true);

		//reverseSpeedLimits
		REQUIRE(car.SetGear(Gear::Reverse) == true);

		REQUIRE(car.SetSpeed(21) == false); 
		REQUIRE(car.SetSpeed(20) == true);
		REQUIRE(car.SetSpeed(0) == true);

		//oneSpeedLimits
		REQUIRE(car.SetGear(Gear::One) == true);

		REQUIRE(car.SetSpeed(0) == true);
		REQUIRE(car.SetSpeed(30) == true);
		REQUIRE(car.SetSpeed(31) == false);

		//twoSpeedLimits
		REQUIRE(car.SetGear(Gear::Two) == true);

		REQUIRE(car.SetSpeed(19) == false);
		REQUIRE(car.SetSpeed(20) == true);
		REQUIRE(car.SetSpeed(50) == true);
		REQUIRE(car.SetSpeed(51) == false);

		//threeSpeedLimits
		REQUIRE(car.SetGear(Gear::Three) == true);

		REQUIRE(car.SetSpeed(29) == false);
		REQUIRE(car.SetSpeed(30) == true);
		REQUIRE(car.SetSpeed(60) == true);
		REQUIRE(car.SetSpeed(61) == false);

		//fourSpeedLimits
		REQUIRE(car.SetGear(Gear::Four) == true);

		REQUIRE(car.SetSpeed(39) == false);
		REQUIRE(car.SetSpeed(40) == true);
		REQUIRE(car.SetSpeed(90) == true);
		REQUIRE(car.SetSpeed(91) == false);

		//fiveSpeedLimits
		REQUIRE(car.SetGear(Gear::Five) == true);

		REQUIRE(car.SetSpeed(49) == false);
		REQUIRE(car.SetSpeed(50) == true);
		REQUIRE(car.SetSpeed(150) == true);
		REQUIRE(car.SetSpeed(151) == false);
	}

	SECTION("Changing speed and gear; check gear limits")
	{
		Car car;
		REQUIRE(car.TurnOnEngine() == true);

		//reverseSpeedLimits and speed < 0
		REQUIRE(car.SetGear(Gear::Reverse) == true);

		REQUIRE(car.SetSpeed(10) == true);
		REQUIRE(car.SetSpeed(-10) == false);
		REQUIRE(car.SetGear(Gear::One) == false);
		REQUIRE(car.SetSpeed(0) == true);
		REQUIRE(car.SetSpeed(-10) == false);

		//oneSpeedLimits
		REQUIRE(car.SetGear(Gear::One) == true);

		REQUIRE(car.SetSpeed(10) == true);
		REQUIRE(car.SetGear(Gear::Reverse) == false);
		REQUIRE(car.SetGear(Gear::Two) == false);
		REQUIRE(car.SetSpeed(20) == true);

		//twoSpeedLimits
		REQUIRE(car.SetGear(Gear::Two) == true);

		REQUIRE(car.SetSpeed(35) == true);
		REQUIRE(car.SetGear(Gear::One) == false);
		REQUIRE(car.SetSpeed(25) == true);
		REQUIRE(car.SetGear(Gear::Three) == false);
		REQUIRE(car.SetSpeed(30) == true);

		//threeSpeedLimits
		REQUIRE(car.SetGear(Gear::Three) == true);

		REQUIRE(car.SetSpeed(55) == true);
		REQUIRE(car.SetGear(Gear::Two) == false);
		REQUIRE(car.SetSpeed(35) == true);
		REQUIRE(car.SetGear(Gear::Four) == false);
		REQUIRE(car.SetSpeed(40) == true);

		//fourSpeedLimits
		REQUIRE(car.SetGear(Gear::Four) == true);

		REQUIRE(car.SetSpeed(65) == true);
		REQUIRE(car.SetGear(Gear::Three) == false);
		REQUIRE(car.SetSpeed(45) == true);
		REQUIRE(car.SetGear(Gear::Five) == false);
		REQUIRE(car.SetSpeed(50) == true);

		//fiveSpeedLimits
		REQUIRE(car.SetGear(Gear::Five) == true);

		REQUIRE(car.SetSpeed(95) == true);
		REQUIRE(car.SetGear(Gear::Four) == false);
		REQUIRE(car.SetSpeed(60) == true);
	}

	SECTION("Switching to neutral gear and changing the speed")
	{
		Car car;
		REQUIRE(car.TurnOnEngine() == true);

		//reverseSpeedLimits
		REQUIRE(car.SetGear(Gear::Reverse) == true);

		REQUIRE(car.SetSpeed(10) == true); 
		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetSpeed(20) == false);
		REQUIRE(car.SetSpeed(0) == true);

		//oneSpeedLimits
		REQUIRE(car.SetGear(Gear::One) == true);

		REQUIRE(car.SetSpeed(25) == true);
		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetSpeed(30) == false);
		REQUIRE(car.SetSpeed(20) == true);

		//twoSpeedLimits
		REQUIRE(car.SetGear(Gear::Two) == true);

		REQUIRE(car.SetSpeed(35) == true);
		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetSpeed(40) == false);
		REQUIRE(car.SetSpeed(30) == true);

		//threeSpeedLimits
		REQUIRE(car.SetGear(Gear::Three) == true);

		REQUIRE(car.SetSpeed(45) == true);
		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetSpeed(50) == false);
		REQUIRE(car.SetSpeed(40) == true);

		//fourSpeedLimits
		REQUIRE(car.SetGear(Gear::Four) == true);

		REQUIRE(car.SetSpeed(55) == true);
		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetSpeed(60) == false);
		REQUIRE(car.SetSpeed(50) == true);

		//fiveSpeedLimits
		REQUIRE(car.SetGear(Gear::Five) == true);

		REQUIRE(car.SetSpeed(65) == true);
		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetSpeed(70) == false);
		REQUIRE(car.SetSpeed(60) == true);
	}

	SECTION("Turning off engine on forward direction")
	{
		Car car;
		REQUIRE(car.TurnOnEngine() == true);
		REQUIRE(car.IsEngineTurnedOn() == true);

		REQUIRE(car.SetGear(Gear::Reverse) == true);
		REQUIRE(car.SetSpeed(10) == true);
		REQUIRE(car.TurnOffEngine() == false);
		REQUIRE(car.IsEngineTurnedOn() == true);

		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetSpeed(0) == true);
		REQUIRE(car.TurnOffEngine() == true);
		REQUIRE(car.IsEngineTurnedOn() == false);
	}

	SECTION("Turning off engine on back direction")
	{
		Car car;
		REQUIRE(car.TurnOnEngine() == true);
		REQUIRE(car.IsEngineTurnedOn() == true);

		REQUIRE(car.SetGear(Gear::One) == true);
		REQUIRE(car.SetSpeed(10) == true);
		REQUIRE(car.TurnOffEngine() == false);
		REQUIRE(car.IsEngineTurnedOn() == true);

		REQUIRE(car.SetGear(Gear::Neutral) == true);
		REQUIRE(car.SetSpeed(0) == true);
		REQUIRE(car.TurnOffEngine() == true);
		REQUIRE(car.IsEngineTurnedOn() == false);
	}
}

TEST_CASE("CarComands")
{
	SECTION("Info")
	{
		Car car;
		std::string inStr = "Info\n";
		std::string outStr = "Engine: turned off\nDirection: on place\nGear: neutral\nSpeed: 0\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CarControl CarControl(car, input, output);

		CarControl.Command();

		REQUIRE(outStr == output.str());
	}

	SECTION("EngineOn")
	{
		Car car;
		std::string inStr = "EngineOn\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CarControl CarControl(car, input, output);

		CarControl.Command();

		REQUIRE(car.IsEngineTurnedOn() == true);
		REQUIRE(car.GetDirection() == Direction::OnPlace);
		REQUIRE(car.GetGear() == Gear::Neutral);
		REQUIRE(car.GetSpeed() == 0);
	}

	SECTION("EngineOff")
	{
		Car car;
		std::string inStr = "EngineOff\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CarControl CarControl(car, input, output);

		CarControl.Command();

		REQUIRE(car.IsEngineTurnedOn() == false);
		REQUIRE(car.GetDirection() == Direction::OnPlace);
		REQUIRE(car.GetGear() == Gear::Neutral);
		REQUIRE(car.GetSpeed() == 0);
	}

	SECTION("SetGear")
	{
		Car car;
		std::string inStr = "EngineOn\nSetGear 1\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CarControl CarControl(car, input, output);

		CarControl.Command();
		CarControl.Command();

		REQUIRE(car.IsEngineTurnedOn() == true);
		REQUIRE(car.GetGear() == Gear::One);
	}

	SECTION("SetSpeed")
	{
		Car car;
		std::string inStr = "EngineOn\nSetGear 1\nSetSpeed 20\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CarControl CarControl(car, input, output);

		CarControl.Command();
		CarControl.Command();
		CarControl.Command();

		REQUIRE(car.IsEngineTurnedOn() == true);
		REQUIRE(car.GetDirection() == Direction::Along);
		REQUIRE(car.GetGear() == Gear::One);
		REQUIRE(car.GetSpeed() == 20);
	}


	SECTION("SetSpeed < 0")
	{
		Car car;
		std::string inStr = "EngineOn\nSetGear -1\nSetSpeed -20\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CarControl CarControl(car, input, output);

		CarControl.Command();
		CarControl.Command();
		CarControl.Command();

		REQUIRE(car.IsEngineTurnedOn() == true);
		REQUIRE(car.GetDirection() == Direction::OnPlace);
		REQUIRE(car.GetGear() == Gear::Reverse);
		REQUIRE(car.GetSpeed() == 0);
	}

	SECTION("GetSpeed < 0")
	{
		Car car;
		std::string inStr = "EngineOn\nSetGear -1\nSetSpeed 10\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CarControl CarControl(car, input, output);

		CarControl.Command();
		CarControl.Command();
		CarControl.Command();

		REQUIRE(car.IsEngineTurnedOn() == true);
		REQUIRE(car.GetDirection() == Direction::Back);
		REQUIRE(car.GetGear() == Gear::Reverse);
		REQUIRE(car.GetSpeed() == 10);
	}

}
