#include "stdafx.h"
#include "MenuManager.h"
#include "Game/State/Base/State.h"

// #### Constructor | Destructor #### //
MenuManager::MenuManager(StateData* stateData)
{
	this->stateData = stateData;
}

MenuManager::~MenuManager()
{
	while (!this->menus.empty())
	{
		delete this->menus.top();
		this->menus.pop();
	}
}
void MenuManager::update()
{
	if (!this->menus.empty())
	{
		if (!this->stateData->states->top()->isPause())
			this->stateData->states->top()->setPause();

		// #### Menus to update #### //
		this->menus.top()->update(this->stateData->states->top()->getMousePosView(), *this->stateData->dt);
		// #### Menus to update #### //

		// #### Check for resume #### //
		if (this->menus.top()->doResume())
		{
			this->menus.top()->endMenu();
			delete this->menus.top();
			this->menus.pop();
		}
		// #### Check for resume #### //
		// #### Check for quit #### //
		else if (this->menus.top()->doQuit())
		{
			this->menus.top()->endMenu();
			delete this->menus.top();
			this->menus.pop();
			this->stateData->states->top()->endState();
		}
		// #### Check for quit #### //
	}
	else
		if (this->stateData->states->top()->isPause())
			this->stateData->states->top()->setUnpause();
}

void MenuManager::render()
{
	if (!this->menus.empty())
		this->menus.top()->render(*this->stateData->window);
}
// #### Constructor | Destructor #### //

// #### Accessors #### //

// #### Accessors #### //

// #### Functions #### //

// #### Functions #### //