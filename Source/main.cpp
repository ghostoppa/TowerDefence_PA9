#include <SFML/Graphics.hpp>
#include "../Headers/LinearPath.h"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(640 , 480), "Game");
    sf::CircleShape shape(10.0f);
    shape.setFillColor(sf::Color::Green);

    /*------ TEST CODE FOR PATH MOVEMENT --------*/
    //(This can be deleted when we don't need it anymore)
    //Basically I'm setting the time to 0, and then creating a test path
    float time = 0;

    LinearPath testPath;
    //(The path is just a square)
    testPath.addPoint(sf::Vector2f(320, 240));
    testPath.addPoint(sf::Vector2f(400, 240));
    testPath.addPoint(sf::Vector2f(400, 320));
    testPath.addPoint(sf::Vector2f(320, 320));
    testPath.addPoint(sf::Vector2f(320, 240));
    /*-------------------------------------------*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        /*---------------- Test Movement code------------------*/
        //                vv This gives a location based on the path, time, and speed
        shape.setPosition(testPath.getPointAlongPath(0.5, time));
        /*-------------------------------------------------*/

        window.clear();
        window.draw(shape);
        

        window.display();
        time += 0.1;
    }

    return 0;
}