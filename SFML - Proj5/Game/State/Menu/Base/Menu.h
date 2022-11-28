#pragma once
#include "Game/GUI/Gui.h"

class Menu
{
protected:
	// #### Variables #### //
	bool resume;	// Do menu need to quit
	bool quit;	// Do state need to quit

	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, sf::RectangleShape> containers;

	std::map<std::string, sf::Texture> textures;	// Map of different textures contained in menu
	std::map<std::string, gui::Text*> texts;	// Map of different texts contained in menu
	std::map<std::string, gui::Button*> buttons;	// Map of different buttons contained in menu
	// #### Variables #### //

	// #### Init Functions #### //
	virtual void initVariables();
	virtual void initContainer(sf::RenderWindow& window) = 0;
	virtual void initText(sf::Font& font) = 0;
	virtual void initButton(sf::Font& font) = 0;
	virtual void initGui(sf::RenderWindow& window, sf::Font& font) = 0;
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	Menu(sf::RenderWindow& window, sf::Font& font);	// Class constructor
	virtual ~Menu();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const bool& doResume() const;
	const bool& doQuit() const;
	std::map<std::string, gui::Text*>& getTexts();
	std::map<std::string, gui::Button*>& getButtons();
	const bool isButtonPressed(const std::string key);
	// #### Accessors #### //

	// #### Functions #### //
	void endMenu();

	void updateButton(const sf::Vector2f& mousePos, const float& dt);
	virtual void update(const sf::Vector2f& mousePos, const float& dt) = 0;

	void renderContainer(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderButton(sf::RenderTarget& target);
	void renderGui(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);
	// #### Functions #### //

};