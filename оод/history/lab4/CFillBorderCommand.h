#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CFillBorderCommand : public ICommand
{
public:
	CFillBorderCommand(CUserInterface* userInterface)
		:m_userInterface(userInterface)
	{}

	void Execute() override;
private:
	CUserInterface* m_userInterface;
};