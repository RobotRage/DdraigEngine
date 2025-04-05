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
panel exitButton;

panel topBarPanel;

// offset the initial starting position of everything so screen can start at 0,0
sf::Vector2f offset; 

bool mouseInBounds(panel * pan, sf::Vector2i & mousePos)
{
	int panXPos = pan->rectangle.getPosition().x - offset.x;
	int panYPos = pan->rectangle.getPosition().y - offset.y;

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
	mousePos = mousePos + sf::Vector2i(viewMainEditor.getCenter());
	for (int i = 0; i < onScreenPanelsParent.size(); i++)
	{
		iterPanelsClick(onScreenPanelsParent.at(i), mousePos);
	}
}

float camMoveSpeed = 0.02f;

bool leftClick = false;
bool rightClick = false;
bool  middleClick = false;

sf::Vector2i middleMouseClickInitial(0,0);
sf::Vector2i middleMouseClickUpdating(0,0);
sf::Vector2f difference(0, 0);
void checkMouseInput() // inf loop
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
	{
		
		if (!middleClick)
		{
			middleMouseClickInitial = sf::Mouse::getPosition(window);
			middleMouseClickUpdating = sf::Mouse::getPosition(window);
			middleClick = true;
		}
		else
		{
			middleMouseClickUpdating = sf::Mouse::getPosition(window);
			difference= sf::Vector2f((middleMouseClickInitial - middleMouseClickUpdating));
			viewMainEditor.move(difference);
			middleMouseClickInitial = sf::Vector2i(middleMouseClickInitial - sf::Vector2i(difference));
			window.setView(viewMainEditor);
		}
		
	}
	else
	{
		middleMouseClickInitial = sf::Vector2i(0, 0);
		middleMouseClickUpdating = sf::Vector2i(0, 0);
		middleClick = false;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (leftClick) { return; }
		leftClick = true;
		checkAllPanelsClick();
	}
	else
	{
		leftClick = false;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		if (rightClick) { return; }
		rightClick = true;
	}
	else
	{
		rightClick = false;
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

sf::Texture logo("images//Ddraig_Goch.png");
sf::Sprite logoSprite(logo);

void movePanelToLock(panel& pan, sf::Vector2f windowPos)
{
	pan.rectangle.setPosition(pan.guiLockedPositionRelative + windowPos);
	if (pan.spriteShow) { pan.sprite->setPosition(pan.guiLockedPositionRelative + windowPos); }
	for (int i = 0; i < pan.childPanels.size(); i++)
	{
		movePanelToLock(*pan.childPanels.at(i), windowPos);
	}
}
void setAllPanelsToScreen()
{
	sf::Vector2f windowPos = viewMainEditor.getCenter();
	for (int i = 0; i < onScreenPanelsParent.size(); i++)
	{
		movePanelToLock(*onScreenPanelsParent.at(i), windowPos);
	}
}

sf::Image icon("images//Ddraig_Goch.png");
void loadDefaultGUIElements()
{
	window.setIcon(icon);
	offset = sf::Vector2(-screenX / 2, -screenY / 2);
	leftSideRoofToFloorPanel.rectangle.setFillColor(turquoise);
	leftSideRoofToFloorPanel.rectangle.setSize(sf::Vector2(screenX/12.0f, screenY));
	leftSideRoofToFloorPanel.guiLockedPositionRelative = (sf::Vector2(0.0f, 0.0f) + offset);
	leftSideRoofToFloorPanel.setAction(&panel::noAction);
	leftSideRoofToFloorPanel.tag = "leftSideRoofToFloorPanel";
	
	rightSideRoofToFloorPanel.rectangle.setFillColor(turquoise);
	rightSideRoofToFloorPanel.rectangle.setSize(sf::Vector2(screenX / 12.0f, screenY));
	rightSideRoofToFloorPanel.guiLockedPositionRelative = (sf::Vector2(screenX - rightSideRoofToFloorPanel.rectangle.getSize().x, 0.0f) + offset);
	rightSideRoofToFloorPanel.setAction(&panel::noAction);
	rightSideRoofToFloorPanel.tag = "rightSideRoofToFloorPanel";

	squarePanel.rectangle.setFillColor(lightGreen);
	squarePanel.rectangle.setSize(sf::Vector2(screenX / 12.0f, screenY/3.0f));
	squarePanel.guiLockedPositionRelative = (sf::Vector2(screenX/2, 20.0f) + offset);
	squarePanel.tag = "squarePanel";
	squarePanel.setAction(&panel::togglePanelVisibility, false);

	rightSideRoofToFloorPanel.childPanels.push_back(&squarePanel); // add as CHILD panel


	topBarPanel.rectangle.setFillColor(turquoise);
	topBarPanel.rectangle.setSize(sf::Vector2(screenX, screenY/25));
	topBarPanel.guiLockedPositionRelative = (sf::Vector2f(0, 0) + offset);
	topBarPanel.setAction(&panel::noAction);
	topBarPanel.tag = "topBarPanel";
	//topBarPanel.sprite = &logoSprite;
	//topBarPanel.sprite->setScale(sf::Vector2f(0.15, 0.2));
	//topBarPanel.spriteShow = true;

	exitButton.guiLockedPositionRelative = (sf::Vector2f(0, 0) + offset);
	exitButton.tag = "logoPanel";
	exitButton.setAction(&panel::noAction);
	exitButton.sprite = &exitBtnSprite;
	exitButton.sprite->setScale(sf::Vector2f(1, 1));
	exitButton.spriteShow = true;
	
	
	queueToDrawPanel(leftSideRoofToFloorPanel);
	queueToDrawPanel(rightSideRoofToFloorPanel);
	queueToDrawPanel(topBarPanel);
	queueToDrawPanel(exitButton);
}

void panel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (visible) { target.draw(rectangle, states); }
}


