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
	if (!this->font.loadFromFile("Resources/Fonts/LouisGeorgeCafe.ttf"))
	{
		throw("ERROR::GAMESTATE: FAILED TO LOAD FONT");
	}
}

void GameState::initTextures()
{
	if (!this->textures["PLAYER_IDLE"].loadFromFile("Resources/Images/Sprites/Player/test.png"))
		throw("ERROR::GAMESTATE: FAILED TO LOAD PLAYER_IDLE TEXTURE");
}

void GameState::initPauseMenu()
{
	this->pMenu = new PauseMenu(*this->stateData->window, this->font);

	this->pMenu->addButton("QUIT", 800.f, "Quit");
}

void GameState::initTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 10, 10);
}

void GameState::initPlayer()
{
	this->player = new Player(0, 0, this->textures["PLAYER_IDLE"]);
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
	this->initPauseMenu();
	this->initTileMap();
	this->initPlayer();
}

GameState::~GameState()
{
	delete this->pMenu;
	delete this->tileMap;
	delete this->player;
}
// #### Constructor | Destructor #### //

// #### Functions #### //
void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))) && this->getKeyTime())
	{
		if (!this->paused)
			this->pauseState();
		else 
			this->unpauseState();
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

void GameState::updatePauseMenuButtons()
{
	if (this->pMenu->isButtonPressed("QUIT"))
		this->endState();
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeyTime(dt);
	this->updateInput(dt);

	if (!this->paused)	// Unpaused
	{
		this->updatePlayerInput(dt);

		this->player->update(dt);
	}
	else	// Paused
	{
		this->pMenu->update(this->mousePosView, dt);
		this->updatePauseMenuButtons();
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

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->stateData->window;

	this->renderTileMap(target);
	this->renderPlayer(target);

	if (this->paused) // Paused menu render
	{
		this->pMenu->render(*target);
	}
}
// #### Functions #### //