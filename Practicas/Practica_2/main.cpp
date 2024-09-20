#include "include/Car.h"
#include "include/Gui.h"
#define SCR_WIDTH 1280
#define SCR_HEIGHT 720
#define FUEL_MAX 100

int main()
{
    // Creacion de la ventana
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "P2 LPOO - Car");

    // Reloj para calcular deltaTime
    sf::Clock clock;

    // Objeto para mostrar la interfaz
    Gui gui(SCR_WIDTH, SCR_HEIGHT);

    // Objeto Car
    Car car(sf::Vector2f(SCR_WIDTH / 2 - 32, SCR_HEIGHT - 150), sf::Vector2f(0, -1), 0, FUEL_MAX);

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

            // Encender / apagar
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                car.TurnOn();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                car.TurnOff();
            }

            // Acelerar
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                car.Accelerate(dt);
            }

            // Frenar
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                car.Brake(dt);
            }
            else
            {
                car.StopBraking();
            }

            // Giro del carro
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                car.TurnRight(dt);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                car.TurnLeft(dt);
            }
            else
            {
                car.StopTurning();
            }

            // Llenar tanque de gasolina
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            {
                car.PumpGas(FUEL_MAX);
            }

            // Reiniciar juego / salir
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                car.reinit(SCR_WIDTH, SCR_HEIGHT, FUEL_MAX);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                window.close();
            }
        }

        window.clear();

        // Dibujar interfaz
        gui.Draw(window, car.getFuel(), car.getSpeed(), FUEL_MAX);

        // Dibujar y actualizar carro
        car.Update(dt, window);

        window.display(); // Mostrar la ventana
    }
    return 0;
}
