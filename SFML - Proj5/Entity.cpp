#include "stdafx.h"
#include "Entity.h"

// #### PRIVATE #### //

// #### Init Functions #### //
void Entity::initVariables()
{
	this->movementComponent = nullptr;
	this->hitboxComponent = nullptr;
}
// #### Init Functions #### //

// #### PRIVATE #### //

// #### Constructor | Destructor #### //
Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->movementComponent;
	delete this->hitboxComponent;
}
// #### Constructor | Destructor #### //

// #### Component Functions #### //
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createHitboxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offsetX, offsetY, width, height);
}
// #### Component Functions #### //

// #### Functions #### //
void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Entity::move(const float dirX, const float dirY, const float& dt)
{
	if (this->movementComponent)
		this->movementComponent->move(dirX, dirY, dt);
}
void Entity::update(const float& dt)
{

}
void Entity::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	if (this->hitboxComponent)
		this->hitboxComponent->render(target);
}
// #### Functions #### //