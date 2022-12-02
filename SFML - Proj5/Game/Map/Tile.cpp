#include "stdafx.h"
#include "Tile.h"

Tile::Tile()
{
}

// #### Constructor | Destructor #### //
Tile::Tile(float x, float y, float gridSizeF, sf::Texture* texture, const sf::IntRect& textureRect)
{
	this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	//this->shape.setOutlineThickness(1.f);
	//this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setPosition(x * gridSizeF, y * gridSizeF);
	this->shape.setTexture(texture);
	this->shape.setTextureRect(textureRect);
}

Tile::~Tile()
{
}
// #### Constructor | Destructor #### //

// #### Accessors #### //
const sf::RectangleShape& Tile::getShape() const
{
	return this->shape;
}
// #### Accessors #### //

// #### Modifiers #### //

// #### Modifiers #### //

// #### Functions #### //
void Tile::update()
{

}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
// #### Functions #### //