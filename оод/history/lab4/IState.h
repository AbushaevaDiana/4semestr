#pragma once
#include "CUserInterface.h"

class CUserInterface;

class IState
{
public:
	virtual void DragAndDrop(CUserInterface* userInterface) = 0;
	virtual void FillShape(CUserInterface* userInterface) = 0;
	virtual void FillBorder(CUserInterface* userInterface) = 0;
	virtual void WidthBorder(CUserInterface* userInterface) = 0;
};
