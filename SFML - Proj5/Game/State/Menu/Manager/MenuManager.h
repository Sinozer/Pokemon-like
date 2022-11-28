#pragma once
#include "../Base/Menu.h"


class StateData;
class MenuManager
{
private:
	// #### Variables #### //
	StateData* stateData;
	bool quitState;
	// #### Variables #### //
public:
	std::stack<Menu*> menus;		// Stack list of differents menus
	// #### Constructor | Destructor #### //
	MenuManager(StateData* stateData);	// Class constructor
	virtual ~MenuManager();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //

	// #### Accessors #### //

	// #### Functions #### //
	void update();
	void render();
	// #### Functions #### //
};

