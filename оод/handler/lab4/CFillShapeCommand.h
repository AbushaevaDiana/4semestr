#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CFillShapeCommand : public ICommand
{
public:
	CFillShapeCommand(CUserInterface* userInterface)
		:m_userInterface(userInterface)
	{}

	void Execute() override;
private:
	CUserInterface* m_userInterface;
};