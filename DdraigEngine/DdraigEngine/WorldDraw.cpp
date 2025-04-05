#include "StandardIncludes.h";
#include "QueueDraw.h";
#include "WorldDraw.h";
#include <filesystem>


std::vector<panel> worldEntities;

//sf::Sprite spriteRes[1];

std::vector<sf::Sprite> spriteResources;
std::vector<sf::Texture> textureResources;

void newSprite()
{
	//for (int i = 0; i < sizeof(spriteRes); i++)
	//{

	//}
}

void loadTexture(sf::String path)
{
	sf::Texture worldEntityDefault;
	worldEntityDefault.loadFromFile(std::filesystem::path(path));
	textureResources.push_back(worldEntityDefault);

	spriteResources.reserve(200); //TODO fix this
}

void loadSpriteResources(sf::Texture & texture)
{
	sf::Sprite worldEntitySprite(texture);
	spriteResources.push_back(worldEntitySprite);
}

int i = 0;
void newEntity()
{
	panel logoPanel;
	logoPanel.rectangle.setPosition(sf::Vector2f(sf::Mouse::getPosition(window))+offset + viewMainEditor.getCenter());
	
	logoPanel.tag = "NEW PANEL "+std::to_string(i);
	logoPanel.setAction(&panel::noAction);

	loadSpriteResources(textureResources[0]);

	logoPanel.sprite = &spriteResources[i];
	i++;

	logoPanel.sprite->setScale(sf::Vector2f(0.15, 0.2));
	logoPanel.spriteShow = true;
	logoPanel.sprite->setPosition(sf::Vector2f(sf::Mouse::getPosition(window))+offset + viewMainEditor.getCenter());
	worldEntities.push_back(logoPanel);
	
}