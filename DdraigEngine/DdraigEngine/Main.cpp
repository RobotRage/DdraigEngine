#include "StandardIncludes.h"
#include "QueueDraw.h"
#include "EngineGUI.h"
#include <windows.h> 

float screenX;
float screenY;

void onStart()
{
    loadDefaultGUIElements();
}

void loop()
{
    checkMouseInput();
}

sf::RenderWindow window;

int main()
{
    screenX = sf::VideoMode::getDesktopMode().size.x/1.3;
    screenY = sf::VideoMode::getDesktopMode().size.y/1.3;

    window.create(sf::VideoMode({ sf::Vector2u(screenX, screenY) }), "DdraigEngine", sf::Style::Close);

    onStart();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        loop();
        
        window.clear();
        draw(window);
        window.display();
    }
}