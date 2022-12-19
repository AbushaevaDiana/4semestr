#pragma once
#include "SaveIn.h"
#include "ImportFrom.h"
#include "CShapeHendler.h"

class CFileHendler
{
public:
	CFileHendler(std::string fileName, CShapeHendler* shapeHendler, CSaveIn* saveIn, CImportFrom* importFrom);

	void Save();
	void Import();

	std::string GetTypeSave() const;
	std::string GetTypeImport() const;

	CSaveIn* m_saveIn;
	CImportFrom* m_importFrom;
	std::string m_fileName;
	CShapeHendler* m_shapeHendler;
};