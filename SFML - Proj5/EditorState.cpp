#include "stdafx.h"
#include "EditorState.h"

// #### Init Functions #### //
void EditorState::initVariables()
{

}

void EditorState::initFonts()
{
	if (!this->font.loadFromFile("Resources/Fonts/LouisGeorgeCafe.ttf"))
	{
		throw("ERROR::EditorState: FAILED TO LOAD FONT");
	}
}

void EditorState::initKeybinds()
{
	std::ifstream ifs("Config/editorstate_keybinds.ini");

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

void EditorState::initPauseMenu()
{
	this->pMenu = new PauseMenu(*this->stateData->window, this->font);

	this->pMenu->addButton("QUIT", 800.f, "Quit");
}

void EditorState::initGui()
{
	this->selectorRect.setSize(sf::Vector2f(this->stateData->gridSize, this->stateData->gridSize));
	this->selectorRect.setFillColor(sf::Color::Transparent);
	this->selectorRect.setOutlineThickness(1.f);
	this->selectorRect.setOutlineColor(sf::Color::Green);
	
	/* Top bar containing dropdown buttons to change editor states */
	this->initButtons();
}

void EditorState::initButtons()
{

}

void EditorState::initTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 10, 10);
}
// #### Init Functions #### //

// #### Constructor | Destructor #### //
EditorState::EditorState(StateData* stateData)
	: State(stateData)
{
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initPauseMenu();
	this->initGui();
	this->initTileMap();
}

EditorState::~EditorState()
{
	for (auto& i : this->buttons)
	{
		delete i.second;
	}

	delete this->pMenu;
}
// #### Constructor | Destructor #### //

// #### Functions #### //
void EditorState::updateInput(const float& dt)
{
	// #### Update player input #### //
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))) && this->getKeyTime())
	{
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
	// #### Update player input #### //
}

void EditorState::updateEditorInput(const float& dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeyTime())	// When left click
	{
		this->tileMap->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0); // Add tile
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->getKeyTime())	// When left click
	{
		this->tileMap->removeTile(this->mousePosGrid.x, this->mousePosGrid.y, 0); // Add tile
	}
}

void EditorState::updateGui(const float& dt)
{
	this->selectorRect.setPosition(this->mousePosGrid.x * this->stateData->gridSize, this->mousePosGrid.y * this->stateData->gridSize);
	this->updateButtons(dt);
}

void EditorState::updateButtons(const float& dt)
{
	for (auto& i : this->buttons)	// Update all buttons in this state
	{
		i.second->update(this->mousePosView, dt);
	}
}

void EditorState::updatePauseMenuButtons(const float& dt)
{
	if (this->pMenu->isButtonPressed("QUIT"))
		this->endState();
}

void EditorState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeyTime(dt);
	this->updateInput(dt);

	if (!this->paused) // Unpaused
	{
		this->updateGui(dt);
		this->updateEditorInput(dt);
	}
	else // Paused
	{
		this->pMenu->update(this->mousePosView, dt);
		this->updatePauseMenuButtons(dt);
	}
}

void EditorState::renderGui(sf::RenderTarget& target)
{
	this->renderButtons(target);
	target.draw(selectorRect);
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}
}

void EditorState::renderTileMap(sf::RenderTarget& target)
{
	this->tileMap->render(target);
}

void EditorState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->stateData->window;

	this->renderTileMap(*target);
	this->renderGui(*target);

	if (this->paused) // Paused menu render
	{
		this->pMenu->render(*target);
	}

	// #### DEBUG #### //
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x + 10, this->mousePosView.y + 10);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(22);
	mouseText.setFillColor(sf::Color::Black);
	std::stringstream ss;
	ss << "X: " << this->mousePosView.x << " " << "Y: " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);
	// #### DEBUG #### //
}
// #### Functions #### //