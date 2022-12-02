#include "stdafx.h"
#include "Game/Entity/Components/MovementComponent.h"

// #### Constructor | Destructor #### //
MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity,
	float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{

}
// #### Constructor | Destructor #### //

// #### Accessors #### //
sf::Vector2f& MovementComponent::getVelocity()
{
	return this->velocity;
}
// #### Accessors #### //

// #### Functions #### //
const bool MovementComponent::getState(const short unsigned state)
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;
		break;
	case MOVING:
		if (this->velocity.x != 0.f || this->velocity.y != 0.f)
			return true;
		break;
	case MOVING_LEFT:
		if (this->velocity.x < 0.f)
			return true;
		break;
	case MOVING_RIGHT:
		if (this->velocity.x > 0.f)
			return true;
		break;
	case MOVING_UP:
		if (this->velocity.y < 0.f)
			return true;
		break;
	case MOVING_DOWN:
		if (this->velocity.y > 0.f)
			return true;
		break;
	default:
		break;
	}	
	return false;
}

void MovementComponent::move(const float dirX, const float dirY, const float& dt)
{
	if (this->velocity.y == 0)
		this->velocity.x += this->acceleration * dirX * dt;
	if (this->velocity.x == 0)
		this->velocity.y += this->acceleration * dirY * dt;
}

void MovementComponent::update(const float& dt)
{
	// #### Decelerate and control max velocity #### //
	if (this->velocity.x > 0.f) // RIGHT
	{
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		this->velocity.x -= this->deceleration * dt;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if (this->velocity.x < 0.f) // LEFT
	{
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		this->velocity.x += this->deceleration * dt;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	if (this->velocity.y > 0.f) // DOWN
	{
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		this->velocity.y -= this->deceleration * dt;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f) // UP
	{
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		this->velocity.y += this->deceleration * dt;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}
	// #### Decelerate and control max velocity #### //

	this->sprite.move(this->velocity * dt);
}
// #### Functions #### //