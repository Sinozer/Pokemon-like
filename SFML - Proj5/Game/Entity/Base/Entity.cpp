#include "stdafx.h"
#include "Entity.h"

// #### PRIVATE #### //

// #### Init Functions #### //
void Entity::initVariables()
{
	this->movementComponent = nullptr;
	this->hitboxComponent = nullptr;
	this->animationComponent = nullptr;
	this->combatComponent = nullptr;
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
	if (this->movementComponent)
		delete this->movementComponent;
	if (this->hitboxComponent)
		delete this->hitboxComponent;
	if (this->animationComponent)
		delete this->animationComponent;
	if (this->combatComponent)
		delete this->combatComponent;
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

void Entity::createHitboxComponent(float offsetX, float offsetY, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(this->sprite, offsetX, offsetY, width, height);
}

void Entity::createAnimationComponent()
{
	this->animationComponent = new AnimationComponent(this->sprite);
}

void Entity::createCombatComponent()
{
	this->combatComponent = new CombatComponent();
}
// #### Component Functions #### //

// #### Accessors #### //
const sf::Vector2f Entity::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::RectangleShape& Entity::getHitbox() const
{
	return this->hitboxComponent->getHitbox();
}
MovementComponent* Entity::getMovementComponent()
{
	return this->movementComponent;
}
sf::Vector2f& Entity::getVelocity()
{
	return this->movementComponent->getVelocity();
}
CombatComponent* Entity::getCombatComponent()
{
	return this->combatComponent;
}
// #### Accessors #### //

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

	if (this->combatComponent)
		this->combatComponent->render(target);
}
// #### Functions #### //