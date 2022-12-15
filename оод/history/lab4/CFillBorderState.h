#pragma once
#include "IState.h"
#include "CDragAndDropState.h"
#include "CFillShapeState.h"
#include "CWidthBorderState.h"

class CFillBorderState : public IState
{
public:
	void DragAndDrop(CUserInterface* userInterface) override;
	void FillShape(CUserInterface* userInterface) override;
	void FillBorder(CUserInterface* userInterface) override;
	void WidthBorder(CUserInterface* userInterface) override;
};