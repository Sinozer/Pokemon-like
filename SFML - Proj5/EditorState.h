#pragma once
#include "GameState.h"
#include "TileMap.h"
#include "PauseMenu.h"
#include "Gui.h"

class EditorState :
	public State
{
private:
	// #### Variables #### //
	sf::Font font;
	PauseMenu* pMenu;

	std::map<std::string, gui::Button*> buttons;

	TileMap* tileMap;

	sf::RectangleShape selectorRect;
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initPauseMenu();
	void initGui();
	void initButtons();
	void initTileMap();
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	EditorState(StateData* stateData);	// Class constructor
	virtual ~EditorState();					// Class destructor
	// #### Constructor | Destructor #### //

	// #### Functions #### //
	void updateInput(const float& dt);
	void updateEditorInput(const float& dt);
	void updateGui(const float& dt);
	void updateButtons(const float& dt);
	void updatePauseMenuButtons(const float& dt);
	void update(const float& dt);
	void renderGui(sf::RenderTarget& target);
	void renderButtons(sf::RenderTarget& target);
	void renderTileMap(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
	// #### Functions #### //
};

