#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CAR_WIDTH = 50;
const int CAR_HEIGHT = 100;

class Car
{
public:
    sf::RectangleShape shape;

    Car(float x, float y, sf::Color color)
    {
        shape.setSize(sf::Vector2f(CAR_WIDTH, CAR_HEIGHT));
        shape.setFillColor(color);
        shape.setPosition(x, y);
    }

    void move(float dx, float dy)
    {
        shape.move(dx, dy);
    }

    bool checkCollision(const Car &other) const
    {
        return shape.getGlobalBounds().intersects(other.shape.getGlobalBounds());
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Car Dodge Game");

    // Carrito del jugador
    Car playerCar(WINDOW_WIDTH / 2 - CAR_WIDTH / 2, WINDOW_HEIGHT - CAR_HEIGHT - 10, sf::Color::Green);

    // Configuración inicial para los autos enemigos
    std::vector<Car> enemyCars;
    float enemySpeed = 1.0f;
    sf::Clock clock;
    float spawnInterval = 1.5f;
    float elapsedTime = 0;

    srand(static_cast<unsigned>(time(0)));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movimiento del carrito del jugador
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerCar.shape.getPosition().x > 0)
        {
            playerCar.move(-1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerCar.shape.getPosition().x < WINDOW_WIDTH - CAR_WIDTH)
        {
            playerCar.move(1.f, 0.f);
        }

        // Spawneo de autos enemigos
        elapsedTime += clock.restart().asSeconds();
        if (elapsedTime >= spawnInterval)
        {
            float spawnX = static_cast<float>(rand() % (WINDOW_WIDTH - CAR_WIDTH));
            enemyCars.emplace_back(spawnX, -CAR_HEIGHT, sf::Color::Red);
            elapsedTime = 0;
        }

        // Movimiento de autos enemigos
        for (auto &enemyCar : enemyCars)
        {
            enemyCar.move(0.f, enemySpeed);
        }

        // Colisión
        for (const auto &enemyCar : enemyCars)
        {
            if (playerCar.checkCollision(enemyCar))
            {
                // Finalizar el juego en caso de colisión
                window.close();
            }
        }

        // Limpiar autos que se han salido de la pantalla
        enemyCars.erase(std::remove_if(enemyCars.begin(), enemyCars.end(),
                                       [](const Car &car)
                                       { return car.shape.getPosition().y > WINDOW_HEIGHT; }),
                        enemyCars.end());

        // Dibujar
        window.clear();
        window.draw(playerCar.shape);
        for (const auto &enemyCar : enemyCars)
        {
            window.draw(enemyCar.shape);
        }
        window.display();
    }

    return 0;
}
