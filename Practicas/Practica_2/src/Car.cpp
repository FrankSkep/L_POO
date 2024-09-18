#include "../include/Car.h"

Car::Car(sf::Vector2f position, sf::Vector2f direction, float speed, float fuel)
{
    // Inicializar atributos
    this->position = position;
    this->direction = direction;
    this->speed = speed;
    this->fuel = fuel;

    // Inicializar variables de estado
    this->isOn = false;
    this->isTurningLeft = false;
    this->isTurningRight = false;

    // Cargar texturas
    textureOff.loadFromFile("assets/apagado.png");
    textureOn.loadFromFile("assets/encendido.png");
    textureLeft.loadFromFile("assets/giro_izquierda.png");
    textureRight.loadFromFile("assets/giro_derecha.png");
    textureBrake.loadFromFile("assets/freno.png");
    spriteCar.setTexture(textureOff); // Por defecto el carro esta apagado
    spriteCar.setPosition(position);
    spriteCar.setScale(1.2, 1.2); // Tamaño del carro
}

// Encender el carro
void Car::TurnOn()
{
    isOn = true;
    spriteCar.setTexture(textureOn);
}

// Apagar el carro
void Car::TurnOff()
{
    isOn = false;
    spriteCar.setTexture(textureOff);

    // Reinicia la dirección y velocidad al apagar
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
    spriteCar.setTexture(textureOff);
}

// Acelerar y frenar
void Car::Accelerate(float deltaTime)
{
    if (isOn && fuel > 0)
    {
        speed += 800 * deltaTime; // Incrementa la velocidad
        fuel -= 35 * deltaTime;   // Decrementa gasolina
    }
}

// Frenar
void Car::Brake(float deltaTime)
{
    if (isOn)
    {
        if (speed > 0)
        {
            speed = std::max(0.0f, speed - 1500 * deltaTime);
            isBraking = true;
        }
    }
}

void Car::StopBraking()
{
    isBraking = false;
}

// Girar
void Car::TurnLeft(float deltaTime)
{
    if (isOn)
    {
        if (speed > 0)
        {
            direction = Rotar(direction, -100 * deltaTime);
            isTurningLeft = true;
        }
    }
}
void Car::TurnRight(float deltaTime)
{
    if (isOn)
    {
        if (speed > 0)
        {
            direction = Rotar(direction, 100 * deltaTime);
            isTurningRight = true;
        }
    }
}

// Detener el giro
void Car::StopTurning()
{
    if (direction.x != 0) // si el carro esta girando
    {
        direction = sf::Vector2f(0, -1);
        spriteCar.setTexture(textureOn);
        isTurningLeft = isTurningRight = false;
    }
}

// Rellenar el tanque de gasolina
void Car::PumpGas(float amount) { fuel = std::min(100.0f, fuel + amount); }

// Actualizar la posición del carro
void Car::Update(float deltaTime, sf::RenderWindow &window)
{
    if (isOn && fuel > 0)
    {
        position += direction * speed * deltaTime;

        // Verificar limites de la ventana
        position.x = std::max(0.0f, std::min((float)window.getSize().x, position.x));
        position.y = std::max(0.0f, std::min((float)window.getSize().y, position.y));
    }

    // Actualizar la textura del carro
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

    spriteCar.setPosition(position); // Actualiza la posición del sprite
    Display(window);
}

// Dibujar el carro en la ventana
void Car::Display(sf::RenderWindow &window)
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