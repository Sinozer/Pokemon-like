#pragma once
#include "Game/Entity/List/Player/Player.h"
#include "Game/Settings/GraphicsSettings.h"

class State;
class StateData
{
public:
	// #### Variables #### //
	float gridSize;
	sf::RenderWindow* window;
	GraphicsSettings* gfxSettings;
	std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;
	sf::Event* sfEvent;
	float* dt;
	// #### Variables #### //

	// #### Constructor #### //
	StateData() {};
	// #### Constructor #### //

	// #### Functions #### //

	// #### Functions #### //
};

class State
{
protected:
	// #### Variables #### //
	StateData* stateData;
	std::map<std::string, int> keyBinds;
	bool pause;
	bool quit;
	float keyTime;
	float keyTimeMax;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;

	std::map<std::string, sf::Texture> textures;	// sfTexture map
	// #### Variables #### //

	// #### Init Functions #### //
	virtual void initKeybinds() = 0;
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	State(StateData* stateData);	// Class constructor
	virtual ~State();					// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const bool& isPause() const;
	const bool& doQuit() const;
	const bool getKeyTime();

	const sf::Vector2i getMousePosScreen() const;
	const sf::Vector2i getMousePosWindow() const;
	const sf::Vector2f getMousePosView() const;
	const sf::Vector2u getMousePosGrid() const;
	// #### Accessors #### //

	// #### Functions #### //
	virtual void setPause();
	virtual void setUnpause();
	virtual void endState();

	virtual void updateMousePositions();
	virtual void updateKeyTime(const float& dt);
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;								// Pure virtual update state
	virtual void render(sf::RenderTarget* target = nullptr) = 0;			// Pure virtual render state
	// #### Functions #### //
};

