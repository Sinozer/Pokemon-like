#pragma once
#include "Player.h"
#include "GraphicsSettings.h"

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
	// #### Variables #### //

	// #### Constructor #### //
	StateData() {};
	// #### Constructor #### //

	// #### Functions #### //

	// #### Functions #### //
};

class State
{
private:
protected:
	// #### Variables #### //
	StateData* stateData;
	std::map<std::string, int> keyBinds;
	bool paused;
	bool quit;
	float keyTime;
	float keyTimeMax;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;
	// #### Ressources #### //
	std::map<std::string, sf::Texture> textures;	// sfTexture map list
	// #### Ressources #### //

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
	const bool& getQuit() const;
	const bool getKeyTime();
	// #### Accessors #### //

	// #### Functions #### //
	void pauseState();
	void unpauseState();

	virtual void endState();

	virtual void updateMousePositions();
	virtual void updateKeyTime(const float& dt);
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;								// Pure virtual update state
	virtual void render(sf::RenderTarget* target = nullptr) = 0;			// Pure virtual render state
	// #### Functions #### //
};

