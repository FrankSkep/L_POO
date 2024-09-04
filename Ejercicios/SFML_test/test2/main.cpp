#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    sf::CircleShape shape(20.f);
    sf::Vector2f pos(50, 50);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::Left)
                    pos.x -= 1;
                if (event.key.code == sf::Keyboard::Right)
                    pos.x += 1;
                if (event.key.code == sf::Keyboard::Up)
                    pos.y -= 1;
                if (event.key.code == sf::Keyboard::Down)
                    pos.y += 1;
            }
        }
        shape.setPosition(pos);
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}