#pragma once
#include "Game/State/Menu/Base/Menu.h"

class EditorPauseMenu
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
	EditorPauseMenu(sf::RenderWindow& window, sf::Font& font);	// Class constructor
	virtual ~EditorPauseMenu();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	
	// #### Accessors #### //

	// #### Functions #### //
	
	// #### Functions #### //

};