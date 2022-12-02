#pragma once
#include "Game/State/Menu/Base/Menu.h"

class GameCombatMenu
	:	public Menu
{
private:
	// #### Variables #### //
	//std::map<std::string, sf::Texture> textures;
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initTextures();
	void initContainer(sf::RenderWindow& window);
	void initText(sf::Font& font);
	void initButton(sf::Font& font);
	void initGui(sf::RenderWindow& window, sf::Font& font);
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	GameCombatMenu(sf::RenderWindow& window, sf::Font& font, sf::Texture ally, sf::Texture opponent);	// Class constructor
	virtual ~GameCombatMenu();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	
	// #### Accessors #### //

	// #### Functions #### //
	void updateButton(const sf::Vector2f& mousePos, const float& dt);
	void update(const sf::Vector2f& mousePos, const float& dt);
	// #### Functions #### //

};