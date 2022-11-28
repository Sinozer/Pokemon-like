#include "stdafx.h"
#include "Game/State/Base/State.h"

// #### Constructor | Destructor #### //
State::State(StateData* stateData)
{
	this->stateData = stateData;
	this->pause = false;
	this->quit = false;
	this->keyTime = 0.f;
	this->keyTimeMax = 10.f;
}

State::~State()
{
	
}
// #### Constructor | Destructor #### //

// #### Accessors #### //
const bool& State::isPause() const
{
	return this->pause;
}

const bool& State::doQuit() const
{
	return this->quit;
}

const bool State::getKeyTime()
{
	if (this->keyTime >= this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}
	return false;
}
const sf::Vector2i State::getMousePosScreen() const
{
	return this->mousePosScreen;
}
const sf::Vector2i State::getMousePosWindow() const
{
	return this->mousePosWindow;
}
const sf::Vector2f State::getMousePosView() const
{
	return this->mousePosView;
}
const sf::Vector2u State::getMousePosGrid() const
{
	return this->mousePosGrid;
}
// #### Accessors #### //

// #### Functions #### //
void State::setPause()
{
	this->pause = true;
}

void State::setUnpause()
{
	this->pause = false;
}

void State::endState()
{
	this->quit = true;
}

void State::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->stateData->window);
	this->mousePosView = this->stateData->window->mapPixelToCoords(sf::Mouse::getPosition(*this->stateData->window));
	this->mousePosGrid = sf::Vector2u(
		static_cast<unsigned>(this->mousePosView.x) / static_cast<unsigned>(this->stateData->gridSize),
		static_cast<unsigned>(this->mousePosView.y) / static_cast<unsigned>(this->stateData->gridSize)
	);
}

void State::updateKeyTime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
		this->keyTime += 50.f * dt;
}
// #### Functions #### //