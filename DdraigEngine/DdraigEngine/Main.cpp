#include "StandardIncludes.h"
#include "QueueDraw.h"
#include "EngineGUI.h"

void onStart()
{
    loadDefaultGUIElements();
}

void loop()
{
    checkMouseInput();
}

sf::RenderWindow window(sf::VideoMode({ screenSize }), "DdraigEngine");

int main()
{
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