#include "stdafx.h"
#include "Tile.h"

Tile::Tile()
{
}

// #### Constructor | Destructor #### //
Tile::Tile(float x, float y, float gridSizeF, sf::Texture& texture)
{
	this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	//this->shape.setFillColor(sf::Color::Blue);
	this->shape.setPosition(x, y);
	this->shape.setTexture(&texture);
}

Tile::~Tile()
{
}
// #### Constructor | Destructor #### //

// #### Accessors #### //

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