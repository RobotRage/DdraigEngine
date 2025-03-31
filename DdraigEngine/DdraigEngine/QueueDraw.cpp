#include "StandardIncludes.h"
#include "EngineGUI.h"

std::vector<panel> onscreenPanels;

void draw(sf::RenderWindow & rw)
{
	for (int i = 0; i < onscreenPanels.size(); i++)
	{
		rw.draw(onscreenPanels[i]);
	}
}

void queueToDraw(panel pan)
{
	onscreenPanels.push_back(pan);
}