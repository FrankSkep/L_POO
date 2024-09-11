#define SCR_WIDTH 800
#define SCR_HEIGHT 600
#define FUEL_MAX 100

#include "Car.h"
#include <iostream>
#include <iomanip> // para setPrecision
#include <sstream> // para ostringstream

int main()
{
    // Crear ventana
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "Practica 2 - LPOO");

    // Cargar la fuente
    sf::Font font;
    if (!font.loadFromFile("assets/Roboto-Regular.ttf"))
    {
        return -1;
    }

    /******** Creacion de la calle *******/
    // Crear la calle (rectángulo gris)
    sf::RectangleShape street(sf::Vector2f(800, 200)); // Ancho 800, Alto 200
    street.setFillColor(sf::Color(100, 100, 100));     // Color gris
    street.setPosition(0, 200);                        // Posición centrada verticalmente en la pantalla

    // Crear las líneas de carril (rectángulos pequeños blancos)
    sf::RectangleShape laneLine(sf::Vector2f(60, 5)); // Ancho 60, Alto 5
    laneLine.setFillColor(sf::Color::White);          // Color blanco

    // Variables para las líneas de carril
    float lineSpacing = 100; // Espaciado entre las líneas
    float lineOffset = 50;   // Offset para centrar la línea de carril en la calle

    /*********************/

    // Crear el texto para mostrar la cantidad de gasolina
    sf::Text fuelText;
    fuelText.setFont(font);                  // Asignar la fuente
    fuelText.setCharacterSize(28);           // Tamaño del texto
    fuelText.setFillColor(sf::Color::White); // Color del texto
    fuelText.setPosition(10, 10);            // Posición del texto en la pantalla

    // Crear el texto para mostrar la velocidad actual
    sf::Text speedText;
    speedText.setFont(font);                  // Asignar la fuente
    speedText.setCharacterSize(28);           // Tamaño del texto
    speedText.setFillColor(sf::Color::White); // Color del texto
    speedText.setPosition(10, 50);            // Posición del texto en la pantalla

    // Crear el texto para mostrar las instrucciones de las teclas
    sf::Text instructionsText;
    instructionsText.setFont(font);                     // Asignar la fuente
    instructionsText.setCharacterSize(20);              // Tamaño del texto
    instructionsText.setFillColor(sf::Color::White);    // Color del texto
    instructionsText.setPosition(10, SCR_HEIGHT - 150); // Posición del texto en la pantalla
    instructionsText.setString("E: Encender\nA: Apagar\nUp: Acelerar\nDown: Frenar\nLeft: Izquierda\nRight: Derecha");

    // Reloj para calcular deltaTime
    sf::Clock clock;

    // Gasolina y velocidad iniciales
    float fuel = FUEL_MAX;
    float speed = 0;

    // Crear el objeto Car
    Car car(sf::Vector2f(SCR_WIDTH / 2 - 32, SCR_HEIGHT - 120), sf::Vector2f(0, -1), 0, 0, FUEL_MAX, false, false, false);

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
        // stream para formatear velocidad
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << speed;
        speedText.setString("Velocidad: " + stream.str() + " km/h");

        // Dibujar todo en la ventana
        window.clear();
        window.draw(street);
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
