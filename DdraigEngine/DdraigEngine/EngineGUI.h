#pragma once

#include "StandardIncludes.h"
#include <vector>
#include <functional>


class panel : public sf::Drawable
{
public:
	bool visible = true;
	
	std::function<void()> action;

    template<typename F, typename... Args>
    void setAction(F&& func, Args&&... args) {
        // Capture this pointer and arguments
        action = [this, func = std::forward<F>(func),
            args = std::make_tuple(std::forward<Args>(args)...)]() mutable {
            std::apply(func, std::tuple_cat(std::make_tuple(this), args));
            };
    }


	sf::RectangleShape rectangle;
	std::string tag;
	std::vector<sf::Text> texts;
    std::vector<panel*> childPanels;

    void togglePanelVisibility(bool vis)
    {
        visible = vis;
        for (int i = 0; i < childPanels.size(); i++)
        {
            childPanels[i]->togglePanelVisibility(visible);
        }
        setAction(&panel::togglePanelVisibility, !visible);
    }


private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
extern std::vector<panel*> onScreenPanelsParent;

void loadDefaultGUIElements();
void checkMouseInput();
