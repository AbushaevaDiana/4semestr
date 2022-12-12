#pragma once
#include "IState.h"
#include "CDragAndDropState.h"
#include "CFillBorderState.h"
#include "CWidthBorderState.h"

class CFillShapeState : public IState
{
public:
	void DragAndDrop(CUserInterface* userInterface) override;
	void FillShape(CUserInterface* userInterface) override;
	void FillBorder(CUserInterface* userInterface) override;
	void WidthBorder(CUserInterface* userInterface) override;
};