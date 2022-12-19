#include "CFileHendler.h"

CFileHendler::CFileHendler(std::string fileName, CShapeHendler* shapeHendler, CSaveIn* saveIn, CImportFrom* importFrom) :
	m_fileName(fileName),
	m_shapeHendler(shapeHendler),
	m_saveIn(saveIn),
	m_importFrom(importFrom)
{};

void CFileHendler::Save()
{
	m_saveIn->Save(m_fileName, m_shapeHendler->GetShapes());
}

void CFileHendler::Import()
{
	m_shapeHendler->RestoreState(m_importFrom->Import(m_fileName));
}

std::string CFileHendler::GetTypeSave() const
{
	return typeid(*m_saveIn).name();
}

std::string CFileHendler::GetTypeImport() const
{
	return typeid(*m_importFrom).name();
}