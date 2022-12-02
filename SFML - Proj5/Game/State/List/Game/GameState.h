#pragma once
#include "Game/State/Base/State.h"
#include "Game/State/Menu/Manager/MenuManager.h"
#include "Game/State/List/Game/Menus/GamePauseMenu.h"
#include "Game/State/List/Game/Menus/GameCombatMenu.h"
#include "Game/Map/TileMap.h"

#include "Game/Entity/Pokemon/Manager/PokemonManager.h"
#include "Game/Map/Map.h"

class GameState :
	public State
{
private:
	// #### Variables #### //
	sf::View view;
	sf::Font font;
	
	Map* map;
	PokemonManager* pokedex;

	bool combat;

	Player* player;

	MenuManager* menuManager;		// Stack list of differents menus
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initMap();
	void initPokedex();
	void initPlayer();
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	GameState(StateData* stateData);	// Class constructor
	virtual ~GameState();					// Class destructor
	// #### Constructor | Destructor #### //

	// #### Functions #### //
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updateMap(const float& dt);
	void updatePokedex();
	void updateMenu();
	void update(const float& dt);

	void renderMap(sf::RenderTarget* target);

	void renderPlayer(sf::RenderTarget* target);
	void renderMenu();
	void render(sf::RenderTarget* target = nullptr);
	// #### Functions #### //
};