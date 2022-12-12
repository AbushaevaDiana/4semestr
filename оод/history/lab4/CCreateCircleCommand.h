#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CCreateCircleCommand : public ICommand
{
public:
	CCreateCircleCommand(CUserInterface* userInterface)
		:m_userInterface(userInterface)
	{}

	void Execute() override;
private:
	CUserInterface* m_userInterface;
};