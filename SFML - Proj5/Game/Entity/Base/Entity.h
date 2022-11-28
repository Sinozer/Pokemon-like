#pragma once
#include "Game/Entity/Components/MovementComponent.h"
#include "Game/Entity/Components/HitboxComponent.h"
#include "Game/Entity/Components/AnimationComponent.h"

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
	AnimationComponent* animationComponent;
	// #### Variables #### //
public:
	// #### Constructor | Destructor #### //
	Entity();						// Class constructor
	virtual ~Entity();				// Class destructor
	// #### Constructor | Destructor #### //

	// #### Component Functions #### //
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createHitboxComponent(float offsetX, float offsetY, float width, float height);
	void createAnimationComponent();
	// #### Component Functions #### //

	// #### Functions #### //
	virtual void setPosition(const float x, const float y);
	virtual void move(const float dirX, const float dirY, const float& dt);	// Move entity

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
	// #### Functions #### //
};

