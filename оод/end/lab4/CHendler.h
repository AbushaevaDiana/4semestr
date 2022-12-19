#pragma once
#include <iostream>
#include <sstream>
#include <functional>
#include "const.h"
#include "CShapeHendler.h"
#include "CUserInterface.h"
#include "CDragAndDropState.h"
#include "CFillShapeState.h"
#include "CFillBorderState.h"
#include "CWidthBorderState.h"
#include "CFillShapeVisitor.h"
#include "CFillBorderVisitor.h"
#include "CWidthBorderVisitor.h"
#include "SaveInText.h"
#include "SaveInBinary.h"
#include "ImportFromText.h"
#include "ImportFromBinary.h"
#include "CFileHendler.h"

class CHendler
{
public:
	static CHendler* GetInstance(std::istream& input, std::ostream& output, sf::RenderWindow& window);

	void ReadShapes() const;
	void HandleEvent(sf::Event event);
	void PrintInfoAboutShapes() const;
	void Draw() const;

private:
	CHendler(std::istream& input, std::ostream& output, sf::RenderWindow& window);

	void DrawShapes() const;
	void DrawUserInterface() const;

	void HandleMouseButtonPressed(sf::Event event) const;
	void HandleKeyPressed(sf::Event event);

	using Hendler = std::function<void(std::istringstream& args)>;
	using ActionMap = std::map<std::string, Hendler>;

	const ActionMap m_actionMap;

	std::istream& m_input;
	std::ostream& m_output;
	sf::RenderWindow& m_window;

	void SaveShapes();
	void ImportShapes();

	static CHendler* m_instance;
	CShapeHendler* m_shapeHendler;
	CFileHendler* m_fileHendler;
	CUserInterface* m_userInterface;
};