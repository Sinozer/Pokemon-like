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
	std::map<std::string, sf::Texture> sheets;
	sf::Texture tileTextureSheet;
	// #### Variables #### //

	// #### Init Function #### //
	void initTexture();
	// #### Init Function #### //
public:
	sf::Texture* selectedSheet;
	// #### Constructor | Destructor #### //
	TileMap(float gridSize, unsigned width, unsigned height);		// Class constructor
	virtual ~TileMap();		// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const sf::Texture* getTileSheet() const;
	// #### Accessors #### //

	// #### Modifiers #### //
	void increaseTextureSet();
	void decreaseTextureSet();
	// #### Modifiers #### //

	// #### Functions #### //
	//void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& textureRect);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);

	void update();
	void render(sf::RenderTarget& target);
	// #### Functions #### //
};

