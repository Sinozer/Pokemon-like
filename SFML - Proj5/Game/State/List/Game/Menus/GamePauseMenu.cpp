#include "stdafx.h"
#include "Game/State/List/Game/Menus/GamePauseMenu.h"

void GamePauseMenu::initVariables()
{

}

void GamePauseMenu::initContainer(sf::RenderWindow& window)
{
	this->containers["BACKGROUND"] = sf::RectangleShape(sf::Vector2f(
		static_cast<float>(window.getSize().x),
		static_cast<float>(window.getSize().y))
	);
	this->containers["BACKGROUND"].setFillColor(sf::Color(20, 20, 20, 100));

	this->containers["RIGHT"] = sf::RectangleShape(sf::Vector2f(
		static_cast<float>(window.getSize().x) / 4.f,
		static_cast<float>(window.getSize().y) - 60.f)
	);
	this->containers["RIGHT"].setFillColor(sf::Color(20, 20, 20, 200));
	this->containers["RIGHT"].setPosition(window.getSize().x / 1.2f - this->containers["RIGHT"].getSize().x / 1.2f, 0.f);
}

void GamePauseMenu::initText(sf::Font& font)
{
	this->texts["RIGHT_TITLE"] = new gui::Text(
		this->containers["RIGHT"].getPosition().x,
		this->containers["RIGHT"].getPosition().y + 40.f,
		this->containers["RIGHT"].getGlobalBounds().width,
		50.f,
		&font, static_cast<std::string>("PAUSED"), 60,
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 0)
	);
}

void GamePauseMenu::initButton(sf::Font& font)
{
	this->buttons["RESUME"] = new gui::Button(
		this->containers["RIGHT"].getPosition().x + this->containers["RIGHT"].getSize().x / 2.f - 125.f, 300.f,
		250.f, 50.f,
		&this->font, "Resume", 50,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["QUIT"] = new gui::Button(
		this->containers["RIGHT"].getPosition().x + this->containers["RIGHT"].getSize().x / 2.f - 125.f, 800.f,
		250.f, 50.f,
		&this->font, "Quit", 50,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void GamePauseMenu::initGui(sf::RenderWindow& window, sf::Font& font)
{
	this->initContainer(window);
	this->initText(font);
	this->initButton(font);
}

// #### Constructor | Destructor #### //
GamePauseMenu::GamePauseMenu(sf::RenderWindow& window, sf::Font& font)
	: Menu(window, font)
{
	this->initVariables();
	this->initGui(window, font);
}

GamePauseMenu::~GamePauseMenu()
{

}
// #### Constructor | Destructor #### //

// #### Accessors #### //

// #### Accessors #### //

// #### Functions #### //
void GamePauseMenu::updateButton(const sf::Vector2f& mousePos, const float& dt)
{
	Menu::updateButton(mousePos, dt);
	if (this->buttons["RESUME"]->isPressed())
		this->resume = true;
	if (this->buttons["QUIT"]->isPressed())
		this->quit = true;
}

void GamePauseMenu::update(const sf::Vector2f& mousePos, const float& dt)
{
	this->updateButton(mousePos, dt);
}
// #### Functions #### //