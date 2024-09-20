#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>

class Gui
{
public:
    Gui(float screenWidth, float screenHeight);
    void Draw(sf::RenderWindow &window, float fuel, float speed, float FUEL_MAX);

private:
    sf::Font font;
    sf::Text fuelText;
    sf::Text speedText;
    sf::Text controlesText;
    sf::RectangleShape road;
    sf::RectangleShape leftLane;
    sf::RectangleShape rightLane;
    sf::RectangleShape line;
    sf::RectangleShape fuelIndicator;
};

#endif