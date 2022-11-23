#include "stdafx.h"
#include "MainMenuState.h"

// #### Init Functions #### //
void MainMenuState::initVariables()
{
	
}

void MainMenuState::initBackground()
{
	this->backGround.setSize(sf::Vector2f(static_cast<float>(this->stateData->window->getSize().x), static_cast<float>(this->stateData->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/menus.png"))
		throw("ERROR::MAINMENUSTATE: FAILED TO LOAD BACKGROUND TEXTURE");
	this->backGround.setTexture(&this->backgroundTexture);


	if (!this->titleTexture.loadFromFile("Resources/Images/large_title.png"))
		throw("ERROR::MAINMENUSTATE: FAILED TO LOAD TITLE TEXTURE");

	this->titleTexture.setSmooth(true);
	this->title.setTexture(this->titleTexture);
	this->title.setScale(sf::Vector2f(0.75f, 0.75f));
	this->title.setPosition(sf::Vector2f((this->stateData->window->getSize().x - this->titleTexture.getSize().x * this->title.getScale().x) / 2, this->stateData->window->getSize().y / 40));
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Resources/Fonts/LouisGeorgeCafe.ttf"))
	{
		throw("ERROR::MAINMENUSTATE: FAILED TO LOAD FONT");
	}
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

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

void MainMenuState::initButtons()
{
	this->buttons["PLAY_STATE"] = new gui::Button((this->stateData->window->getSize().x / 2) - 125.f, 610.f, 250.f, 50.f,
		&this->font, "Play", 50,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EDITOR_STATE"] = new gui::Button((this->stateData->window->getSize().x / 2) - 125.f, 710.f, 250.f, 50.f,
		&this->font, "Editor", 50,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	
	this->buttons["SETTINGS_STATE"] = new gui::Button((this->stateData->window->getSize().x / 2) - 125.f, 810.f, 250.f, 50.f,
		&this->font, "Settings", 50,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	
	this->buttons["EXIT_STATE"] = new gui::Button((this->stateData->window->getSize().x / 2) - 125.f, 910.f, 250.f, 50.f,
		&this->font, "Quit", 50,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

}
// #### Init Functions #### //

// #### Constructor | Destructor #### //
MainMenuState::MainMenuState(StateData* stateData)
	: State(stateData)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	for (auto &i : this->buttons)
	{
		delete i.second;
	}
}
// #### Constructor | Destructor #### //

// #### Functions #### //
void MainMenuState::updateInput(const float& dt)
{
	// #### Update player input #### //

	// #### Update player input #### //
}

void MainMenuState::updateButtons(const float& dt)
{
	for (auto &i : this->buttons)	// Update all buttons in this state
	{
		i.second->update(this->mousePosView, dt);
	}

	if (this->buttons["PLAY_STATE"]->isPressed())	// New game
		this->stateData->states->push(new GameState(this->stateData));

	if (this->buttons["SETTINGS_STATE"]->isPressed())	// New game
		this->stateData->states->push(new SettingsState(this->stateData));

	if (this->buttons["EDITOR_STATE"]->isPressed())	// Editor
		this->stateData->states->push(new EditorState(this->stateData));

	if (this->buttons["EXIT_STATE"]->isPressed())	// Quit application
		this->endState();
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons(dt);
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->stateData->window;

	target->draw(this->backGround);
	target->draw(this->title);

	this->renderButtons(*target);

	// #### DEBUG #### //
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x + 10, this->mousePosView.y + 10);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(22);
	mouseText.setFillColor(sf::Color::White);
	std::stringstream ss;
	ss << "X: " << this->mousePosView.x << " " << "Y: " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);
	// #### DEBUG #### //
}
// #### Functions #### //