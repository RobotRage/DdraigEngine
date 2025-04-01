#include "StandardIncludes.h"
#include <vector>
#include "EngineGUI.h"
#include "QueueDraw.h"

/*

-Check for mouse events (e.g. left and right click, hover)
-Call button functionality as well as updating GUI to draw new elements or stop drawing them


*/

std::vector<panel*> onScreenPanelsParent;

panel leftSideRoofToFloorPanel;
panel rightSideRoofToFloorPanel;
panel squarePanel;

void checkMouseInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		squarePanel.action();
		squarePanel.setAction(&panel::togglePanelVisibility, !squarePanel.visible);
		sf::sleep(sf::milliseconds(100));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		
	}
}

void deleteGUIElement()
{

}

void createNewGUIElementParent()
{

}

void createNewGUIElementChild(panel parent)
{

}

void empty(std::string s) {}


void loadDefaultGUIElements()
{
	leftSideRoofToFloorPanel.rectangle.setFillColor(turquoise);
	leftSideRoofToFloorPanel.rectangle.setSize(sf::Vector2(screenX/12.0f, screenY));
	leftSideRoofToFloorPanel.rectangle.setPosition(sf::Vector2(0.0f, 0.0f));
	//leftSideRoofToFloorPanel.btnAction = empty;
	leftSideRoofToFloorPanel.tag = "leftSideRoofToFloorPanel";

	
	rightSideRoofToFloorPanel.rectangle.setFillColor(turquoise);
	rightSideRoofToFloorPanel.rectangle.setSize(sf::Vector2(screenX / 12.0f, screenY));
	rightSideRoofToFloorPanel.rectangle.setPosition(sf::Vector2(screenX - rightSideRoofToFloorPanel.rectangle.getSize().x, 0.0f));
	//leftSideRoofToFloorPanel.btnAction = empty;
	rightSideRoofToFloorPanel.tag = "rightSideRoofToFloorPanel";

	
	squarePanel.rectangle.setFillColor(lightGreen);
	squarePanel.rectangle.setSize(sf::Vector2(screenX / 12.0f, screenY/3.0f));
	squarePanel.rectangle.setPosition(sf::Vector2(screenX/2, 20.0f));
	squarePanel.tag = "squarePanel";

	squarePanel.setAction(&panel::togglePanelVisibility, false);

	rightSideRoofToFloorPanel.childPanels.push_back(&squarePanel);

	queueToDraw(leftSideRoofToFloorPanel);
	queueToDraw(rightSideRoofToFloorPanel);
}

void panel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (visible) { target.draw(rectangle, states); }
}


