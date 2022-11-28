#pragma once
#include "Game/State/List/Game/GameState.h"
#include "Game/State/List/Editor/EditorState.h"
#include "Game/State/List/Settings/SettingsState.h"
#include "Game/GUI/Gui.h"

class MainMenuState :
	public State
{
private:
	// #### Variables #### //
	sf::Texture backgroundTexture;
	sf::RectangleShape backGround;
	sf::Texture titleTexture;
	sf::Sprite title;

	sf::Font font;

	std::map<std::string, gui::Button*> buttons;
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButtons();
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	MainMenuState(StateData* stateData);	// Class constructor
	virtual ~MainMenuState();					// Class destructor
	// #### Constructor | Destructor #### //

	// #### Functions #### //
	void updateInput(const float& dt);
	void updateButtons(const float& dt);
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
	// #### Functions #### //
};

