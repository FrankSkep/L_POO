#include "../include/Car.h"

// Constantes
const float ACCELERATION_RATE = 800.0f;
const float FUEL_CONSUMPTION_RATE = 35.0f;
const float BRAKE_DECELERATION_RATE = 1500.0f;
const float TURN_ANGLE = 100.0f;
const float MAX_FUEL = 100.0f;

// Constructor
Car::Car(sf::Vector2f position, sf::Vector2f direction, float speed, float fuel)
{
    // Inicializacion atributos
    this->position = position;
    this->direction = direction;
    this->speed = speed;
    this->fuel = fuel;

    // Inicializacion variables de estado
    this->isOn = false;
    this->isTurningLeft = false;
    this->isTurningRight = false;

    // Carga de texturas
    textureOff.loadFromFile("assets/apagado.png");
    textureOn.loadFromFile("assets/encendido.png");
    textureLeft.loadFromFile("assets/giro_izquierda.png");
    textureRight.loadFromFile("assets/giro_derecha.png");
    textureBrake.loadFromFile("assets/freno.png");
    spriteCar.setTexture(textureOff);
    spriteCar.setPosition(position);
    spriteCar.setScale(1.2, 1.2);
}

// Encender el carro
void Car::TurnOn()
{
    isOn = true;
}

// Apagar el carro
void Car::TurnOff()
{
    isOn = false;
    direction = sf::Vector2f(0, -1);
    speed = 0;
}

// Reiniciar el juego
void Car::reinit(float screenWidth, float screenHeight, float fuelInicial)
{
    position = sf::Vector2f(screenWidth / 2 - 32, screenHeight - 150);
    direction = sf::Vector2f(0, -1);
    speed = 0;
    fuel = fuelInicial;
    isOn = false;
    isTurningLeft = false;
    isTurningRight = false;
}

// Acelerar
void Car::Accelerate(float deltaTime)
{
    if (isOn && fuel > 0)
    {
        speed += ACCELERATION_RATE * deltaTime;
        fuel -= FUEL_CONSUMPTION_RATE * deltaTime;
    }
}

// Frenar
void Car::Brake(float deltaTime)
{
    if (isOn && speed > 0)
    {
        speed = std::max(0.0f, speed - BRAKE_DECELERATION_RATE * deltaTime);
        isBraking = true;
    }
}

// Dejar de frenar
void Car::StopBraking()
{
    isBraking = false;
}

// Giro
void Car::TurnLeft(float deltaTime)
{
    if (isOn && speed > 0)
    {
        direction = Rotar(direction, -TURN_ANGLE * deltaTime);
        isTurningLeft = true;
        isTurningRight = false;
    }
}
void Car::TurnRight(float deltaTime)
{
    if (isOn && speed > 0)
    {
        direction = Rotar(direction, TURN_ANGLE * deltaTime);
        isTurningRight = true;
        isTurningLeft = false;
    }
}

// Detener el giro
void Car::StopTurning()
{
    if (isTurningLeft || isTurningRight)
    {
        direction = sf::Vector2f(0, -1);
        isTurningLeft = isTurningRight = false;
    }
}

// Rellenar el tanque de gasolina
void Car::PumpGas(float amount)
{
    fuel = std::min(100.0f, fuel + amount);
}

// Actualizar posición y textura del carro
void Car::Update(float deltaTime, sf::RenderWindow &window)
{
    if (isOn && fuel > 0)
    {
        position += direction * speed * deltaTime;

        // Verificar limites de la ventana
        position.x = std::max(0.0f, std::min((float)window.getSize().x, position.x));
        position.y = std::max(0.0f, std::min((float)window.getSize().y, position.y));
    }

    if (isBraking)
    {
        spriteCar.setTexture(textureBrake);
    }
    else if (isTurningLeft)
    {
        spriteCar.setTexture(textureLeft);
    }
    else if (isTurningRight)
    {
        spriteCar.setTexture(textureRight);
    }
    else if (isOn)
    {
        spriteCar.setTexture(textureOn);
    }
    else
    {
        spriteCar.setTexture(textureOff);
    }

    spriteCar.setPosition(position);
    Draw(window);
}

// Dibujar el carro en la ventana
void Car::Draw(sf::RenderWindow &window)
{
    window.draw(spriteCar);
}

// Rotar un vector en un ángulo dado (proporcionada por el profesor)
sf::Vector2f Car::Rotar(sf::Vector2f v, float deg)
{
    float rad = deg * 3.1416 / 180;
    float sn = sin(rad);
    float cs = cos(rad);
    return sf::Vector2f(v.x * cs - v.y * sn, v.x * sn + v.y * cs);
}

// Getter y setter necesarios
float Car::getFuel() { return fuel; }
float Car::getSpeed() { return speed; }