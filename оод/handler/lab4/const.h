#pragma once
#include <SFML/Graphics.hpp>

const std::string FILE_IN = "input.txt";
const std::string FILE_OUT = "output.txt";

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGTH = 1000;
const std::string WINDOW_TITLE = "Shapes";
const auto WINDOW_STYLE = sf::Style::Default;
const sf::Color CLEAR_WINDOW_COLOR = sf::Color::White;

const int borderThickness = 5;

const int frameThickness = 3;
const sf::Color frameOutlineColor = sf::Color::Black;
const sf::Color frameFillColor = sf::Color::Transparent;

const sf::Color BUTTON_OUTLINE_COLOR = sf::Color::Black;
const int BUTTON_OUTLINE_THICKNESS = 2;
const sf::Color BUTTON_FILL_COLOR = sf::Color::White;
const sf::Color BUTTON_TEXT_COLOR = sf::Color::Black;
const int BUTTON_TEXT_SIZE = 12;
const std::string BUTTON_FONT_FILE = "Montserrat-Bold.ttf";

const std::string DEFAULT_RED_OUTLINE_COLOR = "d60913";
const std::string DEFAULT_RED_FILL_COLOR = "d7625e";

const std::string DEFAULT_YELLOW_OUTLINE_COLOR = "f7a110";
const std::string DEFAULT_YELLOW_FILL_COLOR = "fbd485";

const std::string DEFAULT_GREEN_OUTLINE_COLOR = "085e17";
const std::string DEFAULT_GREEN_FILL_COLOR = "a6cdab";

const std::string DEFAULT_BLUE_OUTLINE_COLOR = "096b6a";
const std::string DEFAULT_BLUE_FILL_COLOR = "8cc4cc";

const std::string DEFAULT_GREY_OUTLINE_COLOR = "707c88";
const std::string DEFAULT_GREY_FILL_COLOR = "b4bccc";

const sf::Color DEFAULT_COLOR = sf::Color::Black;
const float DEFAULT_WIDTH = 5;
const float DEFAULT_DOUBLE_WIDTH = 10;

const std::string DEFAULT_CIRCLE_CENTER_POINT_X = "500";
const std::string DEFAULT_CIRCLE_CENTER_POINT_Y = "200";
const std::string DEFAULT_CIRCLE_RADIUS = "120";
const std::string DEFAULT_CIRCLE_OUTLINE_COLOR = DEFAULT_GREY_OUTLINE_COLOR;
const std::string DEFAULT_CIRCLE_FILL_COLOR = DEFAULT_GREY_FILL_COLOR;

const std::string DEFAULT_RECTANGLE_LEFT_TOP_X = "80";
const std::string DEFAULT_RECTANGLE_LEFT_TOP_Y = "480";
const std::string DEFAULT_RECTANGLE_WIDTH = "240";
const std::string DEFAULT_RECTANGLE_HEIGHT = "240";
const std::string DEFAULT_RECTANGLE_OUTLINE_COLOR = DEFAULT_GREY_OUTLINE_COLOR;
const std::string DEFAULT_RECTANGLE_FILL_COLOR = DEFAULT_GREY_FILL_COLOR;

const std::string DEFAULT_TRIANGLE_FIRST_VERTEX_X = "240";
const std::string DEFAULT_TRIANGLE_FIRST_VERTEX_Y = "80";
const std::string DEFAULT_TRIANGLE_SECOND_VERTEX_X = "80";
const std::string DEFAULT_TRIANGLE_SECOND_VERTEX_Y = "240";
const std::string DEFAULT_TRIANGLE_THIRD_VERTEX_X = "320";
const std::string DEFAULT_TRIANGLE_THIRD_VERTEX_Y = "320";
const std::string DEFAULT_TRIANGLE_OUTLINE_COLOR = DEFAULT_GREY_OUTLINE_COLOR;
const std::string DEFAULT_TRIANGLE_FILL_COLOR = DEFAULT_GREY_FILL_COLOR;