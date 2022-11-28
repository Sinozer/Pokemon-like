#pragma once
#include "Game/State/Base/State.h"
#include "Game/State/Menu/Manager/MenuManager.h"
#include "Game/State/List/Game/Menus/GamePauseMenu.h" // TEMP
#include "Game/State/List/Editor/Menus/EditorPauseMenu.h"
#include "Game/Map/TileMap.h"
#include "Game/GUI/Gui.h"

class EditorState :
	public State
{
private:
	// #### Variables #### //
	sf::Font font;
	sf::Text cursorText;
	MenuManager* menuManager;

	std::map<std::string, gui::ScrollingView*> scrollingViews;
	std::map<std::string, gui::Button*> buttons;

	TileMap* tileMap;

	sf::IntRect textureRect;
	sf::RectangleShape selectorRect;
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void initScrollingViews();
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
	void updateScrollingViews(const float& dt);
	void updateButtons(const float& dt);
	void updateMenu();
	void update(const float& dt);

	void renderGui(sf::RenderTarget& target);
	void renderScrollingViews(sf::RenderTarget& target);
	void renderButtons(sf::RenderTarget& target);
	void renderTileMap(sf::RenderTarget& target);
	void renderMenu();
	void render(sf::RenderTarget* target = nullptr);
	// #### Functions #### //
};

