#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CCreateTriangleCommand : public ICommand
{
public:
	CCreateTriangleCommand(CUserInterface* userInterface)
		:m_userInterface(userInterface)
	{}

	void Execute() override;
private:
	CUserInterface* m_userInterface;
};