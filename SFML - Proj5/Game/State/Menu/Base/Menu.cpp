#include "stdafx.h"
#include "Menu.h"

// #### Init Functions #### //
void Menu::initVariables()
{
	this->quit = false;
}
// #### Init Functions #### //

// #### Constructor | Destructor #### //
Menu::Menu(sf::RenderWindow& window, sf::Font& font)
	: font(font)
{
	
}

Menu::~Menu()
{
	for (auto& i : this->texts)
	{
		delete i.second;
	}

	for (auto& i : this->buttons)
	{
		delete i.second;
	}
}
// #### Constructor | Destructor #### //

// #### Accessors #### //
const bool& Menu::doResume() const
{
	return this->resume;
}

const bool& Menu::doQuit() const
{
	return this->quit;
}

std::map<std::string, gui::Text*>& Menu::getTexts()
{
	return this->texts;
}

std::map<std::string, gui::Button*>& Menu::getButtons()
{
	return this->buttons;
}

const bool Menu::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}
// #### Accessors #### //

// #### Functions #### //
void Menu::endMenu()
{
	// TODO Before quitting menu
}

void Menu::updateButton(const sf::Vector2f& mousePos, const float& dt)
{
	for (auto i : this->buttons)
	{
		i.second->update(mousePos, dt);
	}
}

void Menu::renderContainer(sf::RenderTarget& target)
{
	for (auto i : this->containers)
		target.draw(i.second);
}

void Menu::renderText(sf::RenderTarget& target)
{
	for (auto i : this->texts)
		i.second->render(target);
}

void Menu::renderButton(sf::RenderTarget& target)
{
	for (auto i : this->buttons)
		i.second->render(target);
}

void Menu::renderGui(sf::RenderTarget& target)
{
	this->renderContainer(target);
	this->renderText(target);
	this->renderButton(target);
}

void Menu::render(sf::RenderTarget& target)
{
	this->renderGui(target);
}
// #### Functions #### //