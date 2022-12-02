#include "stdafx.h"
#include "Game/State/List/Game/Menus/GameCombatMenu.h"

void GameCombatMenu::initVariables()
{

}

void GameCombatMenu::initTextures()
{
	this->textures["BACKGROUND"].loadFromFile("Resources/Images/Backgrounds/battle.png");
	this->textures["BACKGROUND"].setSmooth(true);
}

void GameCombatMenu::initContainer(sf::RenderWindow& window)
{
	this->containers["BACKGROUND"] = sf::RectangleShape(sf::Vector2f(
		static_cast<float>(window.getSize().x),
		static_cast<float>(window.getSize().y))
	);
	this->containers["BACKGROUND"].setTexture(&this->textures["BACKGROUND"]);
	
	this->containers["ALLY"] = sf::RectangleShape(sf::Vector2f(
		static_cast<float>(100),
		static_cast<float>(100))
	);
	this->containers["ALLY"].setPosition(0, 0);
	this->containers["ALLY"].setTexture(&this->textures["ALLY"]);
	this->containers["ALLY"].setScale(4.f, 4.f);

	this->containers["OPPONENT"] = sf::RectangleShape(sf::Vector2f(
		static_cast<float>(100),
		static_cast<float>(100))
	);
	this->containers["OPPONENT"].setPosition(window.getSize().x / 1.75f, window.getSize().y / 4);
	this->containers["OPPONENT"].setTexture(&this->textures["OPPONENT"]);
	this->containers["OPPONENT"].setScale(4.f, 4.f);

	this->containers["RIGHT"] = sf::RectangleShape(sf::Vector2f(
		static_cast<float>(window.getSize().x) / 4.f,
		static_cast<float>(window.getSize().y) - 60.f)
	);
	this->containers["RIGHT"].setFillColor(sf::Color(20, 20, 20, 200));
	this->containers["RIGHT"].setPosition(0.f, 0.f);
}

void GameCombatMenu::initText(sf::Font& font)
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

void GameCombatMenu::initButton(sf::Font& font)
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

void GameCombatMenu::initGui(sf::RenderWindow& window, sf::Font& font)
{
	this->initTextures();
	this->initContainer(window);
	this->initText(font);
	this->initButton(font);
}

// #### Constructor | Destructor #### //
GameCombatMenu::GameCombatMenu(sf::RenderWindow& window, sf::Font& font, sf::Texture ally, sf::Texture opponent)
	: Menu(window, font)
{
	this->textures["ALLY"] = ally;
	this->textures["OPPONENT"] = opponent;

	this->initVariables();
	this->initGui(window, font);
}

GameCombatMenu::~GameCombatMenu()
{

}
// #### Constructor | Destructor #### //

// #### Accessors #### //

// #### Accessors #### //

// #### Functions #### //
void GameCombatMenu::updateButton(const sf::Vector2f& mousePos, const float& dt)
{
	Menu::updateButton(mousePos, dt);
	if (this->buttons["RESUME"]->isPressed())
		this->resume = true;
	if (this->buttons["QUIT"]->isPressed())
		this->resume = true;
}

void GameCombatMenu::update(const sf::Vector2f& mousePos, const float& dt)
{
	this->updateButton(mousePos, dt);
}
// #### Functions #### //