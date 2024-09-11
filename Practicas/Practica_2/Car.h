#include <SFML/Graphics.hpp>
#include <cmath>

class Car
{
private:
    sf::Vector2f position;
    sf::Vector2f direction;
    float angle;
    float speed;
    float fuel;
    bool isOn;
    bool isTurningLeft;
    bool isTurningRight;
    sf::Sprite sprite;
    sf::Texture textureOff, textureOn, textureLeft, textureRight, textureBrake;

public:
    Car(sf::Vector2f position, sf::Vector2f direction, float angle, float speed, float fuel,
        bool isOn, bool isTurningLeft, bool isTurningRight)
    {
        this->position = position;
        this->direction = direction;
        this->angle = angle;
        this->speed = speed;
        this->fuel = fuel;
        this->isOn = isOn;
        this->isTurningLeft = isTurningLeft;
        this->isTurningRight = isTurningRight;
        this->textureBrake = textureBrake;

        // Cargar texturas
        textureOff.loadFromFile("assets/apagado.png");
        textureOn.loadFromFile("assets/encendido.png");
        textureLeft.loadFromFile("assets/giro_izquierda.png");
        textureRight.loadFromFile("assets/giro_derecha.png");
        textureBrake.loadFromFile("assets/freno.png");
        sprite.setTexture(textureOff); // Por defecto el carro está apagado
        sprite.setPosition(position);
        sprite.setScale(1.2, 1.2);
    }

    void TurnOn()
    {
        isOn = true;
        sprite.setTexture(textureOn);
    }
    void TurnOff()
    {
        isOn = false;
        sprite.setTexture(textureOff);
    }
    void Accelerate(float deltaTime)
    {
        if (isOn && fuel > 0)
        {
            speed += 850 * deltaTime; // Incrementa la velocidad
            fuel -= 35 * deltaTime;   // Decrementa gasolina
        }
    }

    void Brake(float deltaTime)
    {
        if (isOn)
        {
            if (speed > 0)
            {
                speed = std::max(0.0f, speed - 1500 * deltaTime);
                sprite.setTexture(textureBrake);
            }
        }
    }

    void TurnLeft(float deltaTime)
    {
        if (speed > 0)
        {
            angle -= 250 * deltaTime; // Reduce el giro
            direction = Rotar(direction, -100 * deltaTime);
            sprite.setTexture(textureLeft);
        }
    }
    void TurnRight(float deltaTime)
    {
        if (speed > 0)
        {
            angle += 250 * deltaTime; // Incrementa el giro
            direction = Rotar(direction, 100 * deltaTime);
            sprite.setTexture(textureRight);
        }
    }
    void StopTurning()
    {
        if ((isTurningLeft || isTurningRight) && speed > 0)
        {
            sprite.setTexture(textureOn);
            isTurningLeft = isTurningRight = false;
        }
    }
    void PumpGas(float amount) { fuel = std::min(100.0f, fuel + amount); }

    void Update(float deltaTime, sf::RenderWindow &window)
    {
        if (isOn && fuel > 0)
        {
            // Mover el carro
            position += direction * speed * deltaTime;

            // Verificar límites de la ventana
            if (position.x < 0)
                position.x = 0;
            if (position.y < 0)
                position.y = 0;
            if (position.x + sprite.getGlobalBounds().width > window.getSize().x)
                position.x = window.getSize().x - sprite.getGlobalBounds().width;
            if (position.y + sprite.getGlobalBounds().height > window.getSize().y)
                position.y = window.getSize().y - sprite.getGlobalBounds().height;

            sprite.setPosition(position);
        }
    }

    void Display(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }

    sf::Vector2f Rotar(sf::Vector2f v, float deg)
    {
        float rad = deg * 3.1416 / 180;
        float sn = sin(rad);
        float cs = cos(rad);
        return sf::Vector2f(v.x * cs - v.y * sn, v.x * sn + v.y * cs);
    }

    // Getter y setter
    float getFuel() { return fuel; }

    sf::Vector2f getPosition() { return position; }

    float getSpeed() { return speed; }
};
