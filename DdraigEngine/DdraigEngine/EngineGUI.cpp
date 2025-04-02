#include "StandardIncludes.h"
#include <vector>
#include "EngineGUI.h"
#include "QueueDraw.h"
#include "iostream"

/*
-Check for mouse events (e.g. left and right click, hover)
-Call button functionality as well as updating GUI to draw new elements or stop drawing them

TODO:
    -move/pan view with middle mouse button, update gui to follow camera
	-resize option to resize window, scale all graphics and recreate window and viewport
*/

std::vector<panel*> onScreenPanelsParent;

panel leftSideRoofToFloorPanel;
panel rightSideRoofToFloorPanel;
panel squarePanel;

panel topBarPanel;

bool mouseInBounds(panel * pan, sf::Vector2i & mousePos)
{
	int panXPos = pan->rectangle.getPosition().x;
	int panYPos = pan->rectangle.getPosition().y;

	int panXSiz = pan->rectangle.getSize().x;
	int panYSiz = pan->rectangle.getSize().y;

	std::cout << "mouseX: " << mousePos.x << "   mouseY: " << mousePos.y << std::endl;

	if ((panXPos <= mousePos.x) && (panXPos + panXSiz) >= mousePos.x)
	{
		if ((panYPos <= mousePos.y) && (panYPos + panYSiz) >= mousePos.y)
		{
			return true;
		}
	}
	return false;
}

void iterPanelsClick(panel * pan, sf::Vector2i& mousePos)
{
	if (mouseInBounds(pan, mousePos))
	{
		pan->action();
	}

	for (int i = 0; i < pan->childPanels.size(); i++)
	{
		iterPanelsClick(pan->childPanels.at(i), mousePos);
	}
}
void checkAllPanelsClick()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	for (int i = 0; i < onScreenPanelsParent.size(); i++)
	{
		iterPanelsClick(onScreenPanelsParent.at(i), mousePos);
	}
}

bool releasedL = false; //only trigger event once per click
bool releasedR = false;
void checkMouseInput() // inf loop
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (!releasedL) { return; }
		releasedL = false;
		checkAllPanelsClick();
	}
	else
	{
		releasedL = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		if (!releasedR) { return; }
		releasedR = false;
	}
	else
	{
		releasedR = true;
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



void loadImages()
{

}

sf::Texture exitBtn("images//icon_close.png");
sf::Sprite exitBtnSprite(exitBtn);

//sf::Texture logo("images//Ddraig_Goch.png");
//sf::Sprite logoSprite(logo);

sf::Image icon("images//Ddraig_Goch.png");
void loadDefaultGUIElements()
{
	window.setIcon(icon);

	leftSideRoofToFloorPanel.rectangle.setFillColor(turquoise);
	leftSideRoofToFloorPanel.rectangle.setSize(sf::Vector2(screenX/12.0f, screenY));
	leftSideRoofToFloorPanel.rectangle.setPosition(sf::Vector2(0.0f, 0.0f));
	leftSideRoofToFloorPanel.setAction(&panel::noAction);
	leftSideRoofToFloorPanel.tag = "leftSideRoofToFloorPanel";
	
	rightSideRoofToFloorPanel.rectangle.setFillColor(turquoise);
	rightSideRoofToFloorPanel.rectangle.setSize(sf::Vector2(screenX / 12.0f, screenY));
	rightSideRoofToFloorPanel.rectangle.setPosition(sf::Vector2(screenX - rightSideRoofToFloorPanel.rectangle.getSize().x, 0.0f));
	rightSideRoofToFloorPanel.setAction(&panel::noAction);
	rightSideRoofToFloorPanel.tag = "rightSideRoofToFloorPanel";

	squarePanel.rectangle.setFillColor(lightGreen);
	squarePanel.rectangle.setSize(sf::Vector2(screenX / 12.0f, screenY/3.0f));
	squarePanel.rectangle.setPosition(sf::Vector2(screenX/2, 20.0f));
	squarePanel.tag = "squarePanel";
	squarePanel.setAction(&panel::togglePanelVisibility, false);
	rightSideRoofToFloorPanel.childPanels.push_back(&squarePanel);


	topBarPanel.rectangle.setFillColor(turquoise);
	topBarPanel.rectangle.setSize(sf::Vector2(screenX, screenY/25));
	topBarPanel.rectangle.setPosition(sf::Vector2f(0, 0));
	topBarPanel.setAction(&panel::noAction);
	topBarPanel.tag = "topBarPanel";

	/*
	logoPanel.rectangle.setPosition(sf::Vector2f(0, 0));
	logoPanel.tag = "logoPanel";
	logoPanel.setAction(&panel::noAction);
	logoPanel.sprite = &logoSprite;
	logoPanel.sprite->setScale(sf::Vector2f(0.15, 0.2));
	logoPanel.spriteShow = true;
	*/

	queueToDraw(leftSideRoofToFloorPanel);
	queueToDraw(rightSideRoofToFloorPanel);
	queueToDraw(topBarPanel);
}

void panel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (visible) { target.draw(rectangle, states); }
}


