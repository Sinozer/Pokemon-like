#include "stdafx.h"
#include "SettingsState.h"

// #### Init Functions #### //
void SettingsState::initVariables()
{
	this->interaction = false;

	this->videoModes = sf::VideoMode::getFullscreenModes();
	for (auto& i : this->videoModes)
	{
		this->videoModesStr.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
	}
}

void SettingsState::initBackground()
{
	this->backGround.setSize(sf::Vector2f(static_cast<float>(this->stateData->window->getSize().x), static_cast<float>(this->stateData->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/menus.png"))
		throw("ERROR::MAINMENUSTATE: FAILED TO LOAD BACKGROUND TEXTURE");
	this->backGround.setTexture(&this->backgroundTexture);
}

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Resources/Fonts/LouisGeorgeCafe.ttf"))
	{
		throw("ERROR::MAINMENUSTATE: FAILED TO LOAD FONT");
	}
}

void SettingsState::initKeybinds()
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

void SettingsState::initGui()
{
	this->texts["TITLE"] = new gui::Text(0.f, 30.f, this->stateData->window->getSize().x, 100.f,
		&this->font, "Settings", 75, sf::Color(255, 255, 255, 200), sf::Color(100, 100, 100, 0));

	this->buttons["BACK"] = new gui::Button(50.f, 50.f, 60.f, 50.f,
		&this->font, "<<", 75,
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["APPLY"] = new gui::Button(this->stateData->window->getSize().x - 200.f, this->stateData->window->getSize().y - 112.5f, 150.f, 62.5f,
		&this->font, "Save", 50,
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 50), sf::Color(150, 150, 150, 100), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 200));

	this->dropDownLists["RESOLUTION"] = new gui::DropDownList(1200, 280, 200, 50,
		this->font, this->videoModesStr.data(), 12);

	this->checkBoxes["FULLSCREEN"] = new gui::CheckBox(1200.f, 480.f, 200.f, 50.f,
		&this->font, 50,
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void SettingsState::initText()
{
	this->optionsText.setFont(this->font);
	this->optionsText.setPosition(sf::Vector2f(300.f, 280.f));
	this->optionsText.setCharacterSize(30);
	this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	this->optionsText.setString("Resolution \n\n\nFullscreen \n\n\nVsync \n\n\nAntialiasing");
}
// #### Init Functions #### //

// #### Constructor | Destructor #### //
SettingsState::SettingsState(StateData* stateData)
	: State(stateData)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
	this->initText();
}

SettingsState::~SettingsState()
{
	for (auto& i : this->buttons)
	{
		delete i.second;
	}

	for (auto& i : this->dropDownLists)
	{
		delete i.second;
	}
}
// #### Constructor | Destructor #### //

// #### Functions #### //
void SettingsState::updateInput(const float& dt)
{
	// #### Update player input #### //

	// #### Update player input #### //
}

void SettingsState::updateGui(const float& dt)
{
	this->interaction = false;

	for (auto& i : this->buttons)	// Update all buttons in this state
	{
		i.second->update(this->mousePosView, dt);
	}

	if (this->buttons["BACK"]->isPressed() && !this->interaction)	// Quit application
	{
		this->interaction = true;
		this->endState();
	}

	if (this->buttons["APPLY"]->isPressed() && !this->interaction)	// Apply settings
	{
		system("explorer C:\\");

		/*this->interaction = true;

		this->stateData->gfxSettings->resolution = this->videoModes[this->dropDownLists["RESOLUTION"]->getActiveElementId()];
		if (this->checkBoxes["FULLSCREEN"]->isChecked())
		{
			this->stateData->window->create(this->stateData->gfxSettings->resolution, this->stateData->gfxSettings->title, this->stateData->gfxSettings->fullscreen, this->stateData->gfxSettings->contextSettings);
			this->stateData->gfxSettings->fullscreen = true;
		}
		else
		{
			this->stateData->window->create(this->stateData->gfxSettings->resolution, this->stateData->gfxSettings->title, sf::Style::Titlebar | sf::Style::Close, this->stateData->gfxSettings->contextSettings);
			this->stateData->gfxSettings->fullscreen = false;
		}*/
	}

	for (auto& i : this->checkBoxes)	// Update all checkBoxes in this state
	{
		i.second->update(this->mousePosView, dt);
	}

	if (this->checkBoxes["FULLSCREEN"]->isPressed() && !this->interaction)
	{
		this->interaction = true;
		this->checkBoxes["FULLSCREEN"]->switchState();
	}

	for (auto& i : this->dropDownLists)	// Update all dropDownLists in this state
	{
		i.second->update(this->mousePosView, dt);
	}
}

void SettingsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateGui(dt);
}

void SettingsState::renderGui(sf::RenderTarget& target)
{
	for (auto& i : this->texts)
	{
		i.second->render(target);
	}

	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}

	for (auto& i : this->checkBoxes)
	{
		i.second->render(target);
	}

	for (auto& i : this->dropDownLists)
	{
		i.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->stateData->window;

	target->draw(this->backGround);

	this->renderGui(*target);

	target->draw(this->optionsText);

	// #### DEBUG #### //
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x + 10, this->mousePosView.y + 10);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(22);
	mouseText.setFillColor(sf::Color::Black);
	std::stringstream ss;
	ss << "X: " << this->mousePosView.x << " " << "Y: " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);*/
	// #### DEBUG #### //
}
// #### Functions #### //