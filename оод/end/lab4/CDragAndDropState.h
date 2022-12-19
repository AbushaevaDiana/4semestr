#pragma once
#include "IState.h"
#include "CFillShapeState.h"
#include "CFillBorderState.h"
#include "CWidthBorderState.h"

class CDragAndDropState : public IState
{
public:
	void DragAndDrop(CUserInterface* userInterface) override;
	void FillShape(CUserInterface* userInterface) override;
	void FillBorder(CUserInterface* userInterface) override;
	void WidthBorder(CUserInterface* userInterface) override;
};