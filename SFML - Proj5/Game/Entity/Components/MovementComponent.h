#pragma once

enum movementStates {IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN};

class MovementComponent
{
private:
	// #### Variables #### //
	sf::Sprite& sprite;

	float maxVelocity;	// Maximum speed
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;	// Give direction and speed
	// #### Variables #### //
public:
	// #### Constructor | Destructor #### //
	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementComponent();
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const sf::Vector2f& getVelocity() const;
	// #### Accessors #### //

	// #### Functions #### //
	const bool getState(const short unsigned state);

	void move(const float dirX, const float dirY, const float& dt);
	void update(const float& dt);
	// #### Functions #### //
};