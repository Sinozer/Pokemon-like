#include "stdafx.h"
#include "Player.h"

// #### PRIVATE ####//
// #### Init Functions #### //
void Player::initVariables()
{

}

void Player::initComponents()
{
	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createHitboxComponent(this->sprite, 50.f, 100.f, 55.f, 55.f);
}
	// #### Init Functions #### //
// #### PRIVATE ####//

// #### Constructor | Destructor #### //
Player::Player(float x, float y, sf::Texture& texture)
{
	this->initVariables();
	this->initComponents();

	this->setTexture(texture);
	this->setPosition(x, y);
}

Player::~Player()
{

}
// #### Constructor | Destructor #### //

// #### Funtions #### //
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(1.f, 1.f);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->sprite.setOrigin(155.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);
	}

	this->hitboxComponent->update();
}
// #### Funtions #### //