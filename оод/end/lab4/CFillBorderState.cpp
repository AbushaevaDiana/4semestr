#include "CFillBorderState.h"

void CFillBorderState::DragAndDrop(CUserInterface* userInterface)
{
	userInterface->SetState(new CDragAndDropState());
}

void CFillBorderState::FillShape(CUserInterface* userInterface)
{
	userInterface->SetState(new CFillShapeState());
}

void CFillBorderState::FillBorder(CUserInterface* userInterface)
{
	userInterface->SetState(new CDragAndDropState());
}

void CFillBorderState::WidthBorder(CUserInterface* userInterface)
{
	userInterface->SetState(new CWidthBorderState());
}