#include "stdafx.h"
#include "GameState.h"

// #### PRIVATE #### //
// #### Init Functions #### //
void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keyBinds[key] = this->stateData->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("Resources/Fonts/PokemonXandY.ttf"))
	{
		throw("ERROR::GAMESTATE: FAILED TO LOAD FONT");
	}
}

void GameState::initTextures()
{
	if (!this->textures["PLAYER"].loadFromFile("Resources/Images/Sprites/Player/player.png"))
		throw("ERROR::GAMESTATE: FAILED TO LOAD PLAYER TEXTURE");
}

void GameState::initTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 10, 10);
}

void GameState::initPlayer()
{
	this->player = new Player(0, 0, this->textures["PLAYER"]);
}
// #### Init Functions #### //
// #### PRIVATE #### //

// #### Constructor | Destructor #### //
GameState::GameState(StateData* stateData)
	: State(stateData)
{
	this->initKeybinds();

	this->initFonts();

	this->initTextures();

	this->initTileMap();

	this->initPlayer();

	this->menuManager = new MenuManager(this->stateData);
}

GameState::~GameState()
{
	delete this->tileMap;
	delete this->player;
	delete this->menuManager;
}
// #### Constructor | Destructor #### //

// #### Functions #### //
void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))) && this->getKeyTime())
	{
		this->menuManager->menus.push(new GamePauseMenu(*this->stateData->window, this->font));
	}
}

void GameState::updatePlayerInput(const float& dt)
{
	// #### Update player input #### //
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
		this->player->move(0.f, -1.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);
	// #### Update player input #### //
}

void GameState::updateMenu()
{
	this->menuManager->update();
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeyTime(dt);
	this->updateInput(dt);
	this->updateMenu();

	if (!this->pause)	// Unpaused
	{
		this->updatePlayerInput(dt);
		this->player->update(dt);
	}
}

void GameState::renderTileMap(sf::RenderTarget* target)
{
	this->tileMap->render(*target);
}

void GameState::renderPlayer(sf::RenderTarget* target)
{
	this->player->render(*target);
}

void GameState::renderMenu()
{
	this->menuManager->render();
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->stateData->window;

	this->renderTileMap(target);
	this->renderPlayer(target);
	this->renderMenu();
}
// #### Functions #### //