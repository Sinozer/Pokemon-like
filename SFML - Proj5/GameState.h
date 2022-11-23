#pragma once
#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"

class GameState :
	public State
{
private:
	// #### Variables #### //
	sf::Font font;
	PauseMenu* pMenu;
	
	TileMap* tileMap;
	Player* player;
	// #### Variables #### //

	// #### Functions #### //
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
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
	void updatePauseMenuButtons();
	void update(const float& dt);
	void renderTileMap(sf::RenderTarget* target);
	void renderPlayer(sf::RenderTarget* target);
	void render(sf::RenderTarget* target = nullptr);
	// #### Functions #### //
};