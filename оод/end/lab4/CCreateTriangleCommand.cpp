#include "CCreateTriangleCommand.h"

void CCreateTriangleCommand::Execute()
{
	std::string args = triangleFirstVertexDX + " " + triangleFirstVertexDY +
		+" " + triangleSecondVertexDX + " " + triangleSecondVertexDY +
		+" " + triangleThirdVertexDX + " " + triangleThirdVertexDY +
		+" " + triangleOutlineD + " " + triangleFillD;
	std::istringstream strm(args);
	m_userInterface->m_shapeHendler->CreateTriangle(strm);
}