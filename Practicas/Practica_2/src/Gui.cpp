#include "../include/Gui.h"

Gui::Gui(float screenWidth, float screenHeight)
{
    // Cargar la fuente
    if (!font.loadFromFile("assets/Roboto-Regular.ttf"))
    {
        std::cout << "Error al cargar la fuente" << std::endl;
        return;
    }

    // Texto para mostrar la cantidad de gasolina
    fuelText.setFont(font);
    fuelText.setCharacterSize(30);
    fuelText.setFillColor(sf::Color::White);
    fuelText.setPosition(20, 20);

    // Texto para mostrar la velocidad actual
    speedText.setFont(font);
    speedText.setCharacterSize(30);
    speedText.setFillColor(sf::Color::White);
    speedText.setPosition(20, 60);

    // Texto para mostrar los controles
    controlesText.setFont(font);
    controlesText.setCharacterSize(24);
    controlesText.setFillColor(sf::Color::Yellow);
    controlesText.setPosition(20, screenHeight - 200);
    controlesText.setString("E: Encender\nA: Apagar\nUp: Acelerar\nDown: Frenar\nLeft: Izquierda\nRight: Derecha\nF: Llenar tanque de gasolina\nR: Reiniciar juego\nQ: Salir");

    // Fondo degradado
    road = sf::RectangleShape(sf::Vector2f(screenWidth, screenHeight));
    road.setFillColor(sf::Color(50, 50, 50));
    road.setPosition(0, 0);

    // Carriles (Izquierdo y derecho) con bordes
    leftLane = sf::RectangleShape(sf::Vector2f(screenWidth / 3 - 10, screenHeight));
    leftLane.setFillColor(sf::Color(100, 100, 100));
    leftLane.setOutlineThickness(5);
    leftLane.setOutlineColor(sf::Color::White);
    leftLane.setPosition(screenWidth / 6 - leftLane.getSize().x / 2, 0);

    rightLane = sf::RectangleShape(sf::Vector2f(screenWidth / 3 - 10, screenHeight));
    rightLane.setFillColor(sf::Color(100, 100, 100));
    rightLane.setOutlineThickness(5);
    rightLane.setOutlineColor(sf::Color::White);
    rightLane.setPosition(screenWidth * 5 / 6 - rightLane.getSize().x / 2, 0);

    // Líneas centrales de la calle
    line = sf::RectangleShape(sf::Vector2f(10, screenHeight));
    line.setFillColor(sf::Color::White);
    line.setPosition(screenWidth / 2 - 5, 0);

    // Indicador de nivel de gasolina
    fuelIndicator = sf::RectangleShape(sf::Vector2f(200, 20));
    fuelIndicator.setFillColor(sf::Color::Green);
    fuelIndicator.setPosition(20, 100);
}

void Gui::Draw(sf::RenderWindow &window, float fuel, float speed, float FUEL_MAX)
{
    fuelText.setString("Gasolina: " + std::to_string(static_cast<int>(fuel)));

    std::ostringstream stream; // stream para formatear velocidad
    stream << std::fixed << std::setprecision(2) << speed;
    speedText.setString("Velocidad: " + stream.str() + " km/h");

    // Definir color para cada nivel de gasolina
    if (fuel <= FUEL_MAX && fuel >= 75)
    {
        fuelText.setFillColor(sf::Color::Green);
        fuelIndicator.setFillColor(sf::Color::Green);
    }
    else if (fuel < FUEL_MAX * 0.75 && fuel >= FUEL_MAX * 0.5)
    {
        fuelText.setFillColor(sf::Color::Yellow);
        fuelIndicator.setFillColor(sf::Color::Yellow);
    }
    else if (fuel < FUEL_MAX * 0.5 && fuel >= FUEL_MAX * 0.25)
    {
        fuelText.setFillColor(sf::Color::Red);
        fuelIndicator.setFillColor(sf::Color::Red);
    }
    else
    {
        fuelText.setFillColor(sf::Color::Black);
        fuelIndicator.setFillColor(sf::Color::Black);
    }

    // Actualizar el tamaño del indicador de gasolina
    fuelIndicator.setSize(sf::Vector2f(200 * (fuel / FUEL_MAX), 20));

    window.draw(road);
    window.draw(leftLane);
    window.draw(rightLane);
    window.draw(line);
    window.draw(fuelText);
    window.draw(speedText);
    window.draw(controlesText);
    window.draw(fuelIndicator);
}