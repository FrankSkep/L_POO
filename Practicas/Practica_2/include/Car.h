#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Car
{
private:
    sf::Vector2f position;
    sf::Vector2f direction;
    float speed;
    float fuel;
    bool isOn;
    bool isTurningLeft;
    bool isTurningRight;
    bool isBraking;
    sf::Sprite spriteCar;
    sf::Texture textureOff, textureOn, textureLeft, textureRight, textureBrake;

public:
    Car(sf::Vector2f position, sf::Vector2f direction, float speed, float fuel);

    // Encender el carro
    void TurnOn();

    // Apagar el carro
    void TurnOff();

    // Reiniciar el juego
    void reinit(float screenWidth, float screenHeight, float fuelInicial);

    // Acelerar y frenar
    void Accelerate(float deltaTime);

    // Frenar
    void Brake(float deltaTime);
    void StopBraking();

    // Girar
    void TurnLeft(float deltaTime);
    void TurnRight(float deltaTime);

    // Detener el giro
    void StopTurning();

    // Rellenar el tanque de gasolina
    void PumpGas(float amount);

    // Actualizar la posición del carro
    void Update(float deltaTime, sf::RenderWindow &window);

    // Dibujar el carro en la ventana
    void Display(sf::RenderWindow &window);

    // Rotar un vector en un ángulo dado (proporcionada por el profesor)
    sf::Vector2f Rotar(sf::Vector2f v, float deg);

    // Getter y setter necesarios
    float getFuel();
    float getSpeed();
};
