#pragma once
#include "Game/Entity/Base/Entity.h"

class Player :
	public Entity
{
private:
	// #### Variables #### //

	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initComponents(sf::Texture& textureSet);
	// #### Init Functions #### //
public:
	// #### Constructor | Destructor #### //
	Player(float x, float y, sf::Texture& textureSet);	// Class constructor
	virtual ~Player();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Functions #### //
	void update(const float& dt);
	// #### Functions #### //
};