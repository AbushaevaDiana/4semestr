#pragma once
#include <SFML/Graphics.hpp>

const std::string fileInConst = "txt/input.txt";
const std::string fileOutConst = "txt/output.txt";
const std::string fileSaveImport = "txt/save";

const int windowW = 1500;
const int windowH = 800;
const std::string windowTitle = "Shapes";
const auto windowStyle = sf::Style::Default;
const sf::Color clearWindow = sf::Color::White;

const int borderThickness = 5;

const int frameThickness = 3;
const sf::Color frameOutlineColor = sf::Color::Black;
const sf::Color frameFillColor = sf::Color::Transparent;

const sf::Color buttonOutlineColor = sf::Color::Black;
const int buttonOutlineThickness = 2;
const sf::Color buttonFillColor = sf::Color::White;
const sf::Color buttonTextColor = sf::Color::Black;
const int buttonTextSize = 12;
const std::string buttonFontFile = "Montserrat-Bold.ttf";

const std::string redColor = "FF4500";
const std::string ligthRedColor = "FFC0CB";

const std::string yellowColor = "FFD700";
const std::string ligthYellowColor = "FAFAD2";

const std::string greenColor = "228B22";
const std::string ligthGreenColor = "ADFF2F";

const std::string blueColor = "0000FF";
const std::string ligthBlueColor = "00FFFF";

const std::string greyColor = "696969";
const std::string ligthGreyColor = "DCDCDC";

const sf::Color defaultColor = sf::Color::Black;
const float defaultWidth = 5;
const float doubleWidth = 10;

const std::string circleXD = "500";
const std::string circleYD = "200";
const std::string circleRD = "120";
const std::string circleOutlineD = greyColor;
const std::string circleFillD = ligthGreyColor;

const std::string rectangleXD = "80";
const std::string rectangleYD = "480";
const std::string rectangleWD = "240";
const std::string rectangleHD = "240";
const std::string rectangleOutlineD = greyColor;
const std::string rectangleFillD = ligthGreyColor;

const std::string triangleFirstVertexDX = "240";
const std::string triangleFirstVertexDY = "80";
const std::string triangleSecondVertexDX = "80";
const std::string triangleSecondVertexDY = "240";
const std::string triangleThirdVertexDX = "320";
const std::string triangleThirdVertexDY = "320";
const std::string triangleOutlineD = greyColor;
const std::string triangleFillD = ligthGreyColor;

const std::string circleSaveStr = "circle";
const std::string triangleSaveStr = "triangle";
const std::string rectangleSaveStr = "rectangle";
const std::string startComposite = "start composite >";
const std::string endComposite = "> end composite";