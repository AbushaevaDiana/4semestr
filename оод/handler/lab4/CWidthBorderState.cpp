#include "CWidthBorderState.h"

void CWidthBorderState::DragAndDrop(CUserInterface* userInterface)
{
	userInterface->SetState(new CDragAndDropState());
}

void CWidthBorderState::FillShape(CUserInterface* userInterface)
{
	userInterface->SetState(new CFillShapeState());
}

void CWidthBorderState::FillBorder(CUserInterface* userInterface)
{
	userInterface->SetState(new CFillBorderState());
}

void CWidthBorderState::WidthBorder(CUserInterface* userInterface)
{
	userInterface->SetState(new CDragAndDropState());
}