#pragma once
class AnimationComponent
{
private:
	// #### Variables #### //
	class Animation
	{
	public:
		// #### Variables #### //
		sf::Sprite& sprite;
		float timer;
		float animationTimer;
		unsigned int spriteCount;
		int spaceBetween;
		bool backAndForward;
		bool back;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;
		// #### Variables #### //

		// #### Constructor #### //
		Animation(sf::Sprite& sprite, float animationTimer, unsigned int spriteCount, int spaceBetween, bool backAndForward, sf::IntRect startRect)
			: sprite(sprite), timer(0), animationTimer(animationTimer), spriteCount(spriteCount), spaceBetween(spaceBetween), backAndForward(backAndForward)
		{
			this->back = false;
			this->startRect = startRect;
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(
				this->startRect.left + this->startRect.width * this->spriteCount + this->spaceBetween * spriteCount,
				this->startRect.top, this->startRect.width, this->startRect.height
				);

			this->sprite.setTextureRect(this->startRect);
		}
		// #### Constructor #### //

		// #### Functions #### //
		void play(const float& dt)
		{
			this->timer += 100.f * dt;	// Increment timer
			if (this->timer >= this->animationTimer)
			{
				this->timer = 0.f;	// Reset timer

				if (this->currentRect != this->endRect && !this->back)	// Play animation forward
				{
					this->currentRect.left += this->currentRect.width + this->spaceBetween;
				}
				else if (this->currentRect != this->startRect && this->back)	// Play animation backward
				{
					this->currentRect.left -= this->currentRect.width + this->spaceBetween;
				}
				else	// Reset animation
				{
					if (!this->backAndForward)
						this->currentRect.left = this->startRect.left;
					else
						this->back = !this->back;
				}
				this->sprite.setTextureRect(this->currentRect);
			}
		}
		//void pause();
		void reset()
		{
			this->timer = this->animationTimer;
			this->currentRect = this->startRect;
		}
		// #### Functions #### //
	};

	sf::Sprite& sprite;
	std::map<std::string, Animation*> animations;
	// #### Variables #### //

	// #### Init Functions #### //

	// #### Init Functions #### //
protected:
	// #### Variables #### //

	// #### Variables #### //
public:
	// #### Constructor | Destructor #### //
	AnimationComponent(sf::Sprite& sprite);
	virtual ~AnimationComponent();
	// #### Constructor | Destructor #### //

	// #### Accessors #### //

	// #### Accessors #### //

	// #### Functions #### //
	void addAnimation(const std::string key, float animationTimer, unsigned int spriteCount, int spaceBetween, bool backAndForward, sf::IntRect startRect);
	
	void play(const std::string key, const float& dt);
	// #### Functions #### //
};

