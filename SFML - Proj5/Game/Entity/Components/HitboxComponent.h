#pragma once

class HitboxComponent
{
private:
	// #### Variables #### //
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;

	float offsetX;
	float offsetY;
	// #### Variables #### //

	// #### Init Functions #### //

	// #### Init Functions #### //
protected:
	// #### Variables #### //
	
	// #### Variables #### //
public:
	// #### Constructor | Destructor #### //
	HitboxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height);
	virtual ~HitboxComponent();
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const sf::RectangleShape& getHitbox() const;
	// #### Accessors #### //

	// #### Functions #### //
	bool checkIntersect(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget& target);
	// #### Functions #### //
};