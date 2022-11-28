#pragma once
#include "Game/State/Base/State.h"
#include "Game/GUI/Gui.h"

class SettingsState :
	public State
{
private:
protected:
	// #### Variables #### //
	sf::Texture backgroundTexture;
	sf::RectangleShape backGround;
	sf::Font font;
	sf::Font fontSpe;

	std::map<std::string, gui::Text*> texts;
	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, gui::CheckBox*> checkBoxes;
	std::map<std::string, gui::DropDownList*> dropDownLists;

	bool interaction;

	sf::Text optionsText;

	std::vector<sf::VideoMode> videoModes;
	std::vector<std::string> videoModesStr;

	sf::SoundBuffer buffer;
	sf::Sound sound;
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initGui();
	void initText();
	void initSound();
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	SettingsState(StateData* stateData);	// Class constructor
	virtual ~SettingsState();					// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //

	// #### Accessors #### //

	// #### Functions #### //
	void updateInput(const float& dt);
	void updateGui(const float& dt);
	void update(const float& dt);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
	// #### Functions #### //
};