#pragma once

#include "StandardIncludes.h"
#include <vector>

class button : public sf::Drawable
{
public:
	sf::RectangleShape rectangle;

	int(*btnAction);

	sf::Text text;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

class panel : public sf::Drawable
{
public:
	sf::RectangleShape rectangle;
	
	std::string tag;

	std::list<sf::Text> texts;
	std::list<button> buttons;
	std::list<panel> childPanels;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

void queueToDraw(panel pan);
void loadDefaultGUIElements();