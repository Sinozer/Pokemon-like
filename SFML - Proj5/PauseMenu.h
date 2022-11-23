#pragma once
#include "Gui.h"

class PauseMenu
{
private:
	// #### Variables #### //
	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, gui::Button*> buttons;
	// #### Variables #### //

	// #### Init Functions #### //
	 
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	PauseMenu(sf::RenderWindow& window, sf::Font& font);	// Class constructor
	virtual ~PauseMenu();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	std::map<std::string, gui::Button*>& getButtons();
	// #### Accessors #### //

	// #### Functions #### //
	void addButton(const std::string key, float y, const std::string text);
	const bool isButtonPressed(const std::string key);

	void update(const sf::Vector2f& mousePos, const float& dt);
	void render(sf::RenderTarget& target);
	// #### Functions #### //

};