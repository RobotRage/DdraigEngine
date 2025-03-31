#include "StandardIncludes.h"
#include "QueueDraw.h"
#include "EngineGUI.h"

void onStart()
{
    loadDefaultGUIElements();
}

void loop()
{

}

int main()
{

    sf::RenderWindow window(sf::VideoMode({ screenSize }), "DdraigEngine");

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