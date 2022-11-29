#include "stdafx.h"
#include "EditorState.h"

// #### Init Functions #### //
void EditorState::initVariables()
{
	this->textureRect = sf::IntRect(0, 0, static_cast<int>(this->stateData->gridSize / 2), static_cast<int>(this->stateData->gridSize / 2));

	this->cursorText.setFont(this->font);
	this->cursorText.setCharacterSize(22);
	this->cursorText.setFillColor(sf::Color::White);
}

void EditorState::initFonts()
{
	if (!this->font.loadFromFile("Resources/Fonts/PokemonXandY.ttf"))
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

void EditorState::initGui()
{
	this->selectorRect.setTexture(this->tileMap->getTileSheet());
	this->selectorRect.setTextureRect(this->textureRect);
	this->selectorRect.setSize(sf::Vector2f(this->stateData->gridSize, this->stateData->gridSize));
	this->selectorRect.setFillColor(sf::Color(255, 255, 255, 127));
	this->selectorRect.setOutlineThickness(1.f);
	this->selectorRect.setOutlineColor(sf::Color::Green);

	this->initScrollingViews();

	/* Top bar containing dropdown buttons to change editor states */
	this->initButtons();
}

void EditorState::initScrollingViews()
{
	this->scrollingViews["TEXTURES_SET"] = new gui::TextureSelector(this->stateData->window, this->stateData->gridSize, this->stateData->gridSize, this->stateData->gridSize, this->stateData->gridSize * 8, 14 * this->stateData->gridSize, sf::Color(255, 255, 255, 127), sf::Color(255, 255, 255, 255));
	this->scrollingViews["TEXTURES_SET"]->shapes["MAIN"] = new sf::Sprite(*this->tileMap->selectedSheet);
	this->scrollingViews["TEXTURES_SET"]->shapes["MAIN"]->setPosition(this->stateData->gridSize, this->stateData->gridSize);
	this->scrollingViews["TEXTURES_SET"]->shapes["MAIN"]->setScale(2.f, 2.f);
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
	this->initTileMap();
	this->initGui();

	this->menuManager = new MenuManager(this->stateData);
}

EditorState::~EditorState()
{
	for (auto& i : this->buttons)
	{
		delete i.second;
	}
	delete this->menuManager;
}
// #### Constructor | Destructor #### //

// #### Functions #### //
void EditorState::updateInput(const float& dt)
{
	// #### Update player input #### //
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))) && this->getKeyTime())
	{
		this->menuManager->menus.push(new GamePauseMenu(*this->stateData->window, this->font));
	}
	// #### Update player input #### //
}

void EditorState::updateEditorInput(const float& dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeyTime())	// When left click
	{
		this->tileMap->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect); // Add tile
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->getKeyTime())	// When left click
	{
		this->tileMap->removeTile(this->mousePosGrid.x, this->mousePosGrid.y, 0); // Add tile
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->getKeyTime())
	{
		if (this->textureRect.left < 256 - 32)
			this->textureRect.left += 32;
		else if (this->textureRect.left >= 256 - 32 && this->textureRect.top + this->textureRect.width < 1536 - 32)
		{
			this->textureRect.left = 0;
			this->textureRect.top += 32;
		}
		this->selectorRect.setTextureRect(this->textureRect);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getKeyTime())
	{
		this->tileMap->increaseTextureSet();
		this->scrollingViews["TEXTURES_SET"]->shapes["MAIN"]->setTexture(*this->tileMap->selectedSheet);
		this->selectorRect.setTexture(this->tileMap->getTileSheet());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->getKeyTime())
	{
		this->tileMap->decreaseTextureSet();
		this->scrollingViews["TEXTURES_SET"]->shapes["MAIN"]->setTexture(*this->tileMap->selectedSheet);
		this->selectorRect.setTexture(this->tileMap->getTileSheet());
	}
}

void EditorState::updateGui(const float& dt)
{
	this->cursorText.setPosition(this->mousePosView.x + 30.f, this->mousePosView.y);
	std::stringstream ss;
	ss << "X: " << this->mousePosGrid.x << " " << "Y: " << this->mousePosGrid.y << "\ntX: " << this->textureRect.left << " tY: " << this->textureRect.top;
	this->cursorText.setString(ss.str());

	if (this->mousePosGrid.x * this->stateData->gridSize < this->stateData->window->getSize().x
		&& this->mousePosGrid.y * this->stateData->gridSize < this->stateData->window->getSize().y)
		this->selectorRect.setPosition(this->mousePosGrid.x * this->stateData->gridSize, this->mousePosGrid.y * this->stateData->gridSize);
	
	
	this->updateButtons(dt);
	this->updateScrollingViews(dt);
}

void EditorState::updateScrollingViews(const float& dt)
{
	if (!this->scrollingViews.empty())
		for (auto& i : this->scrollingViews)
			i.second->update(this->mousePosView, dt);
}

void EditorState::updateButtons(const float& dt)
{
	if (!this->buttons.empty())
		for (auto& i : this->buttons)	// Update all buttons in this state
			i.second->update(this->mousePosView, dt);
}

void EditorState::updateMenu()
{
	this->menuManager->update();
}

void EditorState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeyTime(dt);
	this->updateInput(dt);
	this->updateMenu();

	if (!this->pause) // Unpaused
	{
		this->updateGui(dt);
		this->updateEditorInput(dt);
	}
}

void EditorState::renderGui(sf::RenderTarget& target)
{
	this->renderButtons(target);
	target.draw(selectorRect);
	this->renderScrollingViews(target);
}

void EditorState::renderScrollingViews(sf::RenderTarget& target)
{
	if (!this->scrollingViews.empty())
		for (auto& i : this->scrollingViews)
			i.second->render(target);
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	if (!this->buttons.empty())
		for (auto& i : this->buttons)
			i.second->render(target);
}

void EditorState::renderTileMap(sf::RenderTarget& target)
{
	this->tileMap->render(target);
}

void EditorState::renderMenu()
{
	this->menuManager->render();
}

void EditorState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->stateData->window;

	this->renderTileMap(*target);
	this->renderGui(*target);
	target->draw(this->cursorText);
	this->renderMenu();
}
// #### Functions #### //