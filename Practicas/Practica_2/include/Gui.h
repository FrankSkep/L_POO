#pragma once
#include <SFML/Graphics.hpp>
#include <string>  // para std::to_string
#include <iomanip> // para setPrecision
#include <sstream> // para ostringstream
#include <iostream>

class Gui
{
private:
    sf::Font font;
    sf::Text fuelText;
    sf::Text speedText;
    sf::Text controlesText;
    sf::RectangleShape road;
    sf::RectangleShape leftLane;
    sf::RectangleShape rightLane;
    sf::RectangleShape line;

public:
    Gui(float screenWidth, float screenHeight);
    void Draw(sf::RenderWindow &window, float fuel, float speed, float FUEL_MAX);
};