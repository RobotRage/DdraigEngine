#include "StandardIncludes.h";
#include "QueueDraw.h";
#include "WorldDraw.h";
#include <filesystem>

		

std::vector<panel> worldEntities;

std::list<sf::Sprite> spriteResources;
std::vector<sf::Texture> textureResources;

void loadTexture(sf::String path)
{
	sf::Texture worldEntityDefault;
	worldEntityDefault.loadFromFile(std::filesystem::path(path));
	textureResources.push_back(worldEntityDefault);	
}

void loadSpriteResources(sf::Texture & texture)
{
	sf::Sprite worldEntitySprite(texture);
	spriteResources.push_front(worldEntitySprite);
}

void newEntity()
{
	panel entityPanel;
	entityPanel.rectangle.setPosition(sf::Vector2f(sf::Mouse::getPosition(window))+offset + viewMainEditor.getCenter());
	
	entityPanel.tag = "entityPanel";
	entityPanel.setAction(&panel::noAction);

	loadSpriteResources(textureResources[0]);

	entityPanel.sprite = &spriteResources.front();

	entityPanel.sprite->setScale(sf::Vector2f(0.15, 0.2));
	entityPanel.spriteShow = true;
	entityPanel.sprite->setPosition(sf::Vector2f(sf::Mouse::getPosition(window))+offset + viewMainEditor.getCenter());
	worldEntities.push_back(entityPanel);
}