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
    void TurnOn();
    void TurnOff();
    void reinit(float screenWidth, float screenHeight, float fuelInicial);
    void Accelerate(float deltaTime);
    void Brake(float deltaTime);
    void StopBraking();
    void TurnLeft(float deltaTime);
    void TurnRight(float deltaTime);
    void StopTurning();
    void PumpGas(float amount);
    void Update(float deltaTime, sf::RenderWindow &window);
    void Draw(sf::RenderWindow &window);
    sf::Vector2f Rotar(sf::Vector2f v, float deg);
    float getFuel();
    float getSpeed();
};
