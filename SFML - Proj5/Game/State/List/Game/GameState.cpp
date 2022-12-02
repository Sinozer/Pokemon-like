#include "stdafx.h"
#include "GameState.h"

// #### PRIVATE #### //
// #### Init Functions #### //
void GameState::initVariables()
{
	this->combat = false;
}

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

void GameState::initMap()
{
	this->map = new Map(this->player, "Resources/Data/Map/MainMap.json");
}

void GameState::initPokedex()
{
	this->pokedex = new PokemonManager("Resources/Data/pokedex.json");
	this->player->getCombatComponent()->initPokemons(this->pokedex->pokemons);
}

void GameState::initPlayer()
{
	this->player = new Player(1280, 3072, this->textures["PLAYER"]);
}
// #### Init Functions #### //
// #### PRIVATE #### //

// #### Constructor | Destructor #### //
GameState::GameState(StateData* stateData)
	: State(stateData)
{
	this->initVariables();

	this->initKeybinds();

	this->initFonts();

	this->initTextures();

	this->initPlayer();

	this->initMap();

	this->initPokedex();

	this->menuManager = new MenuManager(this->stateData);
}

GameState::~GameState()
{
	delete this->map;
	delete this->pokedex;
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

void GameState::updateMap(const float& dt)
{
	if (this->map)
		this->map->update(dt);
}

void GameState::updatePokedex()
{
}

void GameState::updateMenu()
{
	if (this->player->getCombatComponent()->isCombat() && !this->combat)
	{
		this->combat = true;
		this->player->getCombatComponent()->startCombat();
		this->menuManager->menus.push(new GameCombatMenu(*this->stateData->window, this->font, this->player->getCombatComponent()->getAlly().textures["sprite"], this->player->getCombatComponent()->getOpponent().textures["sprite"]));
	}
	if (this->menuManager->menus.empty() && this->combat)
	{
		this->combat = false;
		this->player->getCombatComponent()->endCombat();
	}

	this->menuManager->update();
}

void GameState::update(const float& dt)
{
	this->stateData->window->setView(this->stateData->window->getDefaultView());

	this->updateMousePositions();
	this->updateKeyTime(dt);
	this->updateInput(dt);
	this->updateMap(dt);
	this->updateMenu();

	if (!this->pause)	// Unpaused
	{
		this->view = sf::View(this->player->getPosition(), sf::Vector2f(this->stateData->window->getSize().x, this->stateData->window->getSize().y));
		this->stateData->window->setView(this->view);
		this->updatePlayerInput(dt);
		this->player->update(dt);
	}
}

void GameState::renderMap(sf::RenderTarget* target)
{
	this->map->render(*target);
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

	this->renderMap(target);
	this->renderPlayer(target);
	this->renderMenu();
}
// #### Functions #### //