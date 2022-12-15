#include "CSetCurrentWidthCommand.h"

void CSetCurrentWidthCommand::Execute()
{
	m_userInterface->SetCurrentWidth(m_width);
}