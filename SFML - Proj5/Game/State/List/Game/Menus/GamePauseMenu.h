#pragma once
#include "Game/State/Menu/Base/Menu.h"

class GamePauseMenu
	:	public Menu
{
private:
	// #### Variables #### //
	
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initContainer(sf::RenderWindow& window);
	void initText(sf::Font& font);
	void initButton(sf::Font& font);
	void initGui(sf::RenderWindow& window, sf::Font& font);
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	GamePauseMenu(sf::RenderWindow& window, sf::Font& font);	// Class constructor
	virtual ~GamePauseMenu();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	
	// #### Accessors #### //

	// #### Functions #### //
	void updateButton(const sf::Vector2f& mousePos, const float& dt);
	void update(const sf::Vector2f& mousePos, const float& dt);
	// #### Functions #### //

};