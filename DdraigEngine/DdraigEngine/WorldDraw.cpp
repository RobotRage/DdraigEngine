#include "StandardIncludes.h";
#include "QueueDraw.h";
#include "WorldDraw.h";


sf::Texture worldEntityDefault("images//Ddraig_Goch.png");
std::vector<panel> worldEntities;

void newEntity()
{
	sf::Sprite worldEntitySprite(worldEntityDefault);
	panel logoPanel;
	logoPanel.rectangle.setPosition(sf::Vector2f(sf::Mouse::getPosition()));
	logoPanel.tag = "logoPanel";
	logoPanel.setAction(&panel::noAction);
	logoPanel.sprite = &worldEntitySprite;
	logoPanel.sprite->setScale(sf::Vector2f(0.15, 0.2));
	logoPanel.spriteShow = true;

	worldEntities.push_back(logoPanel);
}