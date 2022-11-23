#include "stdafx.h"
#include "State.h"

// #### Constructor | Destructor #### //
State::State(StateData* stateData)
{
	this->stateData = stateData;
	this->paused = false;
	this->quit = false;
	this->keyTime = 0.f;
	this->keyTimeMax = 10.f;
}

State::~State()
{

}
// #### Constructor | Destructor #### //

// #### Accessors #### //
const bool& State::getQuit() const
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
// #### Accessors #### //

// #### Functions #### //
void State::pauseState()
{
	this->paused = true;
}

void State::unpauseState()
{
	this->paused = false;
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