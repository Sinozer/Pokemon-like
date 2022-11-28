#include "stdafx.h"
#include "Game/Entity/Components/AnimationComponent.h"

// #### Constructor | Destructor #### //
AnimationComponent::AnimationComponent(sf::Sprite& sprite)
	: sprite(sprite)
{

}
AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations)
		delete i.second;
}
// #### Constructor | Destructor #### //

// #### Accessors #### //

// #### Accessors #### //

// #### Functions #### //
void AnimationComponent::addAnimation(const std::string key, float animationTimer, unsigned int spriteCount, int spaceBetween, bool backAndForward, sf::IntRect startRect)
{
	this->animations[key] = new Animation(this->sprite, animationTimer, spriteCount, spaceBetween, backAndForward, startRect);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	this->animations[key]->play(dt);
}

// #### Functions #### //
