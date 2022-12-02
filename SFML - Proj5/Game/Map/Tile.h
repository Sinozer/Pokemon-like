#pragma once

class Tile
{
protected:
	// #### Variables #### //
	sf::RectangleShape shape;
	// #### Variables #### //
public:
	// #### Constructor | Destructor #### //
	Tile();
	Tile(float x, float y, float gridSizeF, sf::Texture* texture, const sf::IntRect& textureRect);		// Class constructor
	virtual ~Tile();	// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const sf::RectangleShape& getShape() const;
	// #### Accessors #### //

	// #### Modifiers #### //

	// #### Modifiers #### //

	// #### Functions #### //
	void update();
	void render(sf::RenderTarget& target);
	// #### Functions #### //
};

