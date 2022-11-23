#pragma once
#include "Tile.h"

class TileMap
{
private:
	// #### Variables #### //
	float gridSizeF;	// Float GridSize
	unsigned gridSizeU;	// Unsigned GridSize
	sf::Vector2u maxSize;	// TileMap max size
	unsigned layers;
	std::vector<std::vector<std::vector<Tile*>>> map;	// X Y Z Tile
	sf::Texture tileTextureSheet;
	// #### Variables #### //
public:
	// #### Constructor | Destructor #### //
	TileMap(float gridSize, unsigned width, unsigned height);		// Class constructor
	virtual ~TileMap();		// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	
	// #### Accessors #### //

	// #### Modifiers #### //
	
	// #### Modifiers #### //

	// #### Functions #### //
	void addTile(const unsigned x, const unsigned y, const unsigned z);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);

	void update();
	void render(sf::RenderTarget& target);
	// #### Functions #### //
};

