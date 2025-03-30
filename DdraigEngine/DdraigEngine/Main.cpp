#include "StandardIncludes.h"
#include "QueueDraw.h"


void loop()
{

}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 1000 }), "DdraigEngine");


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