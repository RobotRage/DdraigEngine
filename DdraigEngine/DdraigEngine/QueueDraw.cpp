#include "StandardIncludes.h"
#include "EngineGUI.h"


void drawAllPanels(sf::RenderWindow& rw, panel & pan)
{
	rw.draw(pan);
	if (pan.spriteShow) { rw.draw(*pan.sprite); }
	for (int i = 0; i < pan.childPanels.size(); i++)
	{
		drawAllPanels(rw, *pan.childPanels.at(i));
	}
}

void draw(sf::RenderWindow & rw)
{
	for (int i = 0; i < onScreenPanelsParent.size(); i++)
	{
		drawAllPanels(rw, *onScreenPanelsParent.at(i));
	}
}

void queueToDraw(panel & pan)
{
	onScreenPanelsParent.push_back(&pan);
}

void deletePanel(std::string tag)
{
	for (int i = 0; i < onScreenPanelsParent.size(); i++)
	{
		if (onScreenPanelsParent.at(i)->tag == tag)
		{
			onScreenPanelsParent.erase(onScreenPanelsParent.begin() + i);
		}
	}
}