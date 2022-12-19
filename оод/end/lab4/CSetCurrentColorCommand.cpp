#include "CSetCurrentColorCommand.h"

void CSetCurrentColorCommand::Execute()
{
	m_userInterface->SetCurrentColor(m_color);
}