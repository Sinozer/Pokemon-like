#include "stdafx.h"
#include "Player.h"

// #### PRIVATE ####//
// #### Init Functions #### //
void Player::initVariables()
{

}

void Player::initComponents(sf::Texture& textureSet)
{
	this->createMovementComponent(240.f, 4800.f, 1200.f);
	this->createHitboxComponent(16, 32, 55.f, 55.f);
	this->createAnimationComponent();
	this->sprite.scale(sf::Vector2f(4.f, 4.f));

	this->animationComponent->addAnimation("MOVING_DOWN", 15.f, 2, 0, true, sf::IntRect(6, 1, 19, 30));
	this->animationComponent->addAnimation("MOVING_LEFT", 15.f, 2, 0, true, sf::IntRect(5, 32, 21, 26));
	this->animationComponent->addAnimation("MOVING_UP", 15.f, 2, 0, true, sf::IntRect(6, 59, 20, 30));
	this->animationComponent->addAnimation("MOVING_RIGHT", 15.f, 2, 0, true, sf::IntRect(3, 88, 21, 30));

	this->createCombatComponent();
}
// #### Init Functions #### //
// #### PRIVATE ####//

// #### Constructor | Destructor #### //
Player::Player(float x, float y, sf::Texture& textureSet)
{
	this->initVariables();

	this->setTexture(textureSet);
	this->setPosition(x, y);

	this->initComponents(textureSet);
}

Player::~Player()
{

}
// #### Constructor | Destructor #### //

// #### Funtions #### //
void Player::update(const float& dt)
{
	if (this->movementComponent && this->animationComponent)
	{
		this->movementComponent->update(dt);
		if (this->movementComponent->getState(MOVING_DOWN))
		{
			this->animationComponent->play("MOVING_DOWN", dt);
		}
		else if (this->movementComponent->getState(MOVING_LEFT))
		{
			this->animationComponent->play("MOVING_LEFT", dt);
		}
		else if (this->movementComponent->getState(MOVING_UP))
		{
			this->animationComponent->play("MOVING_UP", dt);
		}
		else if (this->movementComponent->getState(MOVING_RIGHT))
		{
			this->animationComponent->play("MOVING_RIGHT", dt);
		}
	}

	this->hitboxComponent->update();

	/*system("cls");
	std::cout << "x: " << this->sprite.getTextureRect().left << std::endl;
	std::cout << "y: " << this->sprite.getTextureRect().top << std::endl;
	std::cout << "w: " << this->sprite.getTextureRect().width << std::endl;
	std::cout << "h: " << this->sprite.getTextureRect().height << std::endl;*/
}
// #### Funtions #### //