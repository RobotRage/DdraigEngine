#include "StandardIncludes.h"
#include <vector>
#include "EngineGUI.h"

/*

-Check for mouse events (e.g. left and right click, hover)
-Call button functionality as well as updating GUI to draw new elements or stop drawing them


*/


void deleteGUIElement()
{

}

void createNewGUIElement()
{

}

void loadDefaultGUIElements()
{
	panel leftSideRoofToFloorPanel;
	leftSideRoofToFloorPanel.rectangle.setPosition(sf::Vector2(0.0f,0.0f));
	leftSideRoofToFloorPanel.rectangle.setFillColor(sf::Color::Blue);
	leftSideRoofToFloorPanel.rectangle.setSize(sf::Vector2(screenX/10.0f, screenY));

	leftSideRoofToFloorPanel.tag = "leftSideRoofToFloorPanel";

	queueToDraw(leftSideRoofToFloorPanel);
}

void panel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
}

void button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
}