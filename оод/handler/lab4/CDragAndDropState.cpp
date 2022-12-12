#include "CDragAndDropState.h"

void CDragAndDropState::DragAndDrop(CUserInterface* userInterface)
{}

void CDragAndDropState::FillShape(CUserInterface* userInterface)
{
	userInterface->SetState(new CFillShapeState());
}

void CDragAndDropState::FillBorder(CUserInterface* userInterface)
{
	userInterface->SetState(new CFillBorderState());
}

void CDragAndDropState::WidthBorder(CUserInterface* userInterface)
{
	userInterface->SetState(new CWidthBorderState());
}
