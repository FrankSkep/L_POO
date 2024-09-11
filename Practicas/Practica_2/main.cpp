#include "Car.h"
#include <iostream>
#include <iomanip> // para setPrecision
#include <sstream> // para ostringstream
#define SCR_WIDTH 1280
#define SCR_HEIGHT 720
#define FUEL_MAX 100

int main()
{
    // Crear ventana
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "P2 LPOO - Car");

    // Cargar la fuente
    sf::Font font;
    if (!font.loadFromFile("assets/Roboto-Regular.ttf"))
    {
        return -1;
    }

    // Crear la calle (simple rectángulo gris)
    sf::RectangleShape road(sf::Vector2f(SCR_WIDTH, SCR_HEIGHT));
    road.setFillColor(sf::Color(50, 50, 50)); // Color gris para la calle
    road.setPosition(0, 0);

    // Crear los carriles (más claros)
    sf::RectangleShape leftLane(sf::Vector2f(SCR_WIDTH / 3 - 10, SCR_HEIGHT));
    leftLane.setFillColor(sf::Color(100, 100, 100));                   // Color gris claro para los carriles
    leftLane.setPosition(SCR_WIDTH / 6 - leftLane.getSize().x / 2, 0); // Carril izquierdo

    sf::RectangleShape rightLane(sf::Vector2f(SCR_WIDTH / 3 - 10, SCR_HEIGHT));
    rightLane.setFillColor(sf::Color(100, 100, 100));                        // Color gris claro para los carriles
    rightLane.setPosition(SCR_WIDTH * 5 / 6 - rightLane.getSize().x / 2, 0); // Carril derecho

    // Crear las líneas centrales de la calle (blancas)
    sf::RectangleShape line(sf::Vector2f(10, SCR_HEIGHT));
    line.setFillColor(sf::Color::White);
    line.setPosition(SCR_WIDTH / 2 - 5, 0);

    // Crear el texto para mostrar la cantidad de gasolina
    sf::Text fuelText;
    fuelText.setFont(font);                  // Asignar la fuente
    fuelText.setCharacterSize(26);           // Tamaño del texto
    fuelText.setFillColor(sf::Color::White); // Color del texto
    fuelText.setPosition(10, 10);            // Posición del texto en la pantalla

    // Crear el texto para mostrar la velocidad actual
    sf::Text speedText;
    speedText.setFont(font);                  // Asignar la fuente
    speedText.setCharacterSize(26);           // Tamaño del texto
    speedText.setFillColor(sf::Color::White); // Color del texto
    speedText.setPosition(10, 50);            // Posición del texto en la pantalla

    // Crear el texto para mostrar las instrucciones de las teclas
    sf::Text instructionsText;
    instructionsText.setFont(font);                     // Asignar la fuente
    instructionsText.setCharacterSize(26);              // Tamaño del texto
    instructionsText.setFillColor(sf::Color::White);    // Color del texto
    instructionsText.setPosition(10, SCR_HEIGHT - 200); // Posición del texto en la pantalla
    instructionsText.setString("E: Encender\nA: Apagar\nUp: Acelerar\nDown: Frenar\nLeft: Izquierda\nRight: Derecha");

    // Reloj para calcular deltaTime
    sf::Clock clock;

    // Gasolina y velocidad iniciales
    float fuel = FUEL_MAX;
    float speed = 0;

    // Crear el objeto Car
    Car car(sf::Vector2f(SCR_WIDTH / 2 - 32, SCR_HEIGHT - 150), sf::Vector2f(0, -1), 0, 0, FUEL_MAX, false, false, false);

    // Bucle principal del juego
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Manejo de eventos del teclado
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                car.TurnOn();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                car.TurnOff();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                car.Accelerate(dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                car.Brake(dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                car.TurnRight(dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                car.TurnLeft(dt);
            }

            // Dejar de girar y frenar
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                car.StopTurning();
            }
        }

        // Actualizar el estado del carro
        car.Update(dt, window);

        // Actualizar el texto de la gasolina
        if (fuel <= FUEL_MAX && fuel >= 75)
        {
            fuelText.setFillColor(sf::Color::Green);
        }
        else if (fuel < FUEL_MAX * 0.75 && fuel >= FUEL_MAX * 0.5)
        {
            fuelText.setFillColor(sf::Color::Yellow);
        }
        else if (fuel < FUEL_MAX * 0.5 && fuel >= FUEL_MAX * 0.25)
        {
            fuelText.setFillColor(sf::Color::Red);
        }
        else
        {
            fuelText.setFillColor(sf::Color::Black);
        }

        // Actualizar el texto de la gasolina
        fuel = car.getFuel();
        fuelText.setString("Gasolina: " + std::to_string(static_cast<int>(fuel)));

        // Actualizar el texto de la velocidad
        speed = car.getSpeed();
        std::ostringstream stream; // stream para formatear velocidad
        stream << std::fixed << std::setprecision(2) << speed;
        speedText.setString("Velocidad: " + stream.str() + " km/h");

        // Dibujar todo en la ventana
        window.clear();
        window.draw(road);
        window.draw(leftLane);
        window.draw(rightLane);
        window.draw(line);
        window.draw(fuelText);
        window.draw(speedText);
        window.draw(instructionsText);

        // Dibujar el carro
        car.Display(window);

        // Mostrar lo que se ha dibujado
        window.display();
    }

    return 0;
}
