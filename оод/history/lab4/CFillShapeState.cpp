#include "CFillShapeState.h"

void CFillShapeState::DragAndDrop(CUserInterface* userInterface)
{
	userInterface->SetState(new CDragAndDropState());
}

void CFillShapeState::FillShape(CUserInterface* userInterface)
{
	userInterface->SetState(new CDragAndDropState());
}

void CFillShapeState::FillBorder(CUserInterface* userInterface)
{
	userInterface->SetState(new CFillBorderState());
}

void CFillShapeState::WidthBorder(CUserInterface* userInterface)
{
	userInterface->SetState(new CWidthBorderState());
}