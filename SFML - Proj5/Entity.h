#pragma once

#include "MovementComponent.h"
#include "HitboxComponent.h"

class Entity
{
private:
	// #### Variables #### //
	
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	// #### Init Functions #### //
protected:
	// #### Variables #### //
	sf::Sprite sprite;

	MovementComponent* movementComponent;
	HitboxComponent* hitboxComponent;
	// #### Variables #### //
public:
	// #### Constructor | Destructor #### //
	Entity();						// Class constructor
	virtual ~Entity();				// Class destructor
	// #### Constructor | Destructor #### //

	// #### Component Functions #### //
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createHitboxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height);
	// #### Component Functions #### //

	// #### Functions #### //
	virtual void setPosition(const float x, const float y);
	virtual void move(const float dirX, const float dirY, const float& dt);	// Move entity

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
	// #### Functions #### //
};

