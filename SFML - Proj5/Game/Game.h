#pragma once
#include "Game/State/List/MainMenu/MainMenuState.h"

class Game
{
private:
	// #### Variables #### //
	GraphicsSettings gfxSettings;
	StateData stateData;
	sf::RenderWindow* window;		// sfWindow
	sf::Event sfEvent;				// sfEvent

	sf::Clock dtClock;				// deltaClock
	float dt;						// detaTime

	std::stack<State*> states;		// Stack list of differents states

	std::map<std::string, int> supportedKeys;	// Keys supported by application

	float gridSize;

	sf::Cursor cursor;
	// #### Variables #### //

	// #### Init functions #### //
	void initVariables();
	void initGraphicsSettings();
	void initWindow();				// Create sfWindow
	void initKeys();
	void initStateData();
	void initStates();
	// #### Init functions #### //
public:
	// #### Constructor | Destructor #### //
	Game();							// Class constructor
	virtual ~Game();				// Class destructor
	// #### Constructor | Destructor #### //

	// #### Functions #### //
	void endApplication();

	void handleEvents();			// Handle sfEvents
	void updateDT();				// Update delta time with time it takes to update and render game on one frame
	void update();					// Update game
	void render();					// Render game
	void run();						// Main loop
	// #### Functions #### //
};

