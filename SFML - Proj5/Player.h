#pragma once
#include "Entity.h"

class Player :
	public Entity
{
private:
	// #### Variables #### //

	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initComponents();
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	Player(float x, float y, sf::Texture& texture);	// Class constructor
	virtual ~Player();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Functions #### //
	void update(const float& dt);
	// #### Functions #### //
};