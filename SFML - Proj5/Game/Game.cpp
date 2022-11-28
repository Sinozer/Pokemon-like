#include "stdafx.h"
#include "Game.h"

// #### Init functions #### //
void Game::initVariables()
{
	this->window = nullptr;
	this->dt = 0.f;
	this->gridSize = 64.f; // (?) TO CHANGE
}

void Game::initGraphicsSettings()
{
	this->gfxSettings.loadFromFile("Config/window.ini");
}

void Game::initWindow()
{
	if (this->gfxSettings.fullscreen)
		this->window = new sf::RenderWindow(this->gfxSettings.resolution, this->gfxSettings.title, sf::Style::Fullscreen, this->gfxSettings.contextSettings);
	else
		this->window = new sf::RenderWindow(this->gfxSettings.resolution, this->gfxSettings.title, sf::Style::Titlebar | sf::Style::Close, this->gfxSettings.contextSettings);
	
	this->window->setFramerateLimit(this->gfxSettings.framerateLimit);
	this->window->setVerticalSyncEnabled(this->gfxSettings.verticalSync);
}

void Game::initKeys()
{
	std::ifstream ifs("Config/supported_keys.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		int keyValue = 0;

		while (ifs >> key >> keyValue)
		{
			this->supportedKeys[key] = keyValue;
		}
	}

	ifs.close();

	// #### DEBUG #### //
	/*for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}*/
	// #### DEBUG #### //
}

void Game::initStateData()
{
	this->stateData.gridSize = this->gridSize;
	this->stateData.window = this->window;
	this->stateData.gfxSettings = &this->gfxSettings;
	this->stateData.supportedKeys = &this->supportedKeys;
	this->stateData.states = &this->states;
	this->stateData.dt = &this->dt;

	this->cursor.loadFromSystem(sf::Cursor::Hand);
	this->window->setMouseCursor(this->cursor);
}

void Game::initStates()
{
	this->states.push(new MainMenuState(&this->stateData));
}
// #### Init functions #### //

// #### Constructor | Destructor #### //
Game::Game()
{
	this->initVariables();
	this->initGraphicsSettings();
	this->initWindow();
	this->initKeys();
	this->initStateData();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}
// #### Constructor | Destructor #### //


// #### Functions #### //
void Game::endApplication()
{
	// #### DEBUG #### //
	//std::cout << "Ending application" << std::endl;
	// #### DEBUG #### //
}

void Game::handleEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::update()
{
	this->handleEvents();

	if (!this->states.empty())
	{
		// #### Items to update #### //
		this->states.top()->update(this->dt);
		// #### Items to update #### //

		// #### Check for quit #### //
		if (this->states.top()->doQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
		// #### Check for quit #### //
	}
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	// #### Items to render #### //
	if (!this->states.empty())
		this->states.top()->render(this->window);
	// #### Items to render #### //

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDT();
		this->update();
		this->render();
	}
}
// #### Functions #### //