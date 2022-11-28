#pragma once
#include "Game/State/Base/State.h"
#include "Game/State/Menu/Manager/MenuManager.h"
#include "Game/State/List/Game/Menus/GamePauseMenu.h"
#include "Game/Map/TileMap.h"

class GameState :
	public State
{
private:
	// #### Variables #### //
	sf::Font font;
	
	TileMap* tileMap;
	Player* player;

	MenuManager* menuManager;		// Stack list of differents menus
	// #### Variables #### //

	// #### Functions #### //
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initTileMap();
	void initPlayer();
	// #### Functions #### //
public:
	// #### Constructor | Destructor #### //
	GameState(StateData* stateData);	// Class constructor
	virtual ~GameState();					// Class destructor
	// #### Constructor | Destructor #### //

	// #### Functions #### //
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updateMenu();
	void update(const float& dt);

	void renderTileMap(sf::RenderTarget* target);
	void renderPlayer(sf::RenderTarget* target);
	void renderMenu();
	void render(sf::RenderTarget* target = nullptr);
	// #### Functions #### //
};