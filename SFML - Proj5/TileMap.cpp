#include "stdafx.h"
#include "TileMap.h"

// #### Constructor | Destructor #### //
TileMap::TileMap(float gridSize, unsigned width, unsigned height)
{
	this->gridSizeF = gridSize;
	this->gridSizeU = static_cast<unsigned>(this->gridSizeF);
	this->maxSize.x = width;
	this->maxSize.y = height;
	this->layers = 1;

	this->map.resize(this->maxSize.x, std::vector<std::vector<Tile*>>());
	for (size_t x = 0; x < this->maxSize.x; x++)
		for (size_t y = 0; y < this->maxSize.y; y++)
		{
			this->map[x].resize(this->maxSize.y, std::vector<Tile*>());

			for (size_t z = 0; z < this->layers; z++)
				this->map[x][y].resize(this->layers, nullptr);
		}

	if (!this->tileTextureSheet.loadFromFile("Resources/Images/Tiles/ground.jpg"))
		throw("ERROR::TILEMAP: FAILED TO LOAD IMAGE");
}

TileMap::~TileMap()
{
	for (size_t x = 0; x < this->maxSize.x; x++)
		for (size_t y = 0; y < this->maxSize.y; y++)
			for (size_t z = 0; z < this->layers; z++)
				delete this->map[x][y][z];
}
// #### Constructor | Destructor #### //

// #### Accessors #### //

// #### Accessors #### //

// #### Modifiers #### //

// #### Modifiers #### //


// #### Functions #### //
void TileMap::addTile(const unsigned x, const unsigned y, const unsigned z)
{
	if (x >= 0 && x < this->maxSize.x
		&& y >= 0 && y < this->maxSize.y
		&& z >= 0 && z < this->layers) // Prevents out of bounds
	{
		if (this->map[x][y][z] == nullptr) // Check if tile is empty
			this->map[x][y][z] = new Tile(x * this->gridSizeF, y * this->gridSizeF, this->gridSizeF, this->tileTextureSheet);
	}
}

void TileMap::removeTile(const unsigned x, const unsigned y, const unsigned z)
{
	if (x >= 0 && x < this->maxSize.x
		&& y >= 0 && y < this->maxSize.y
		&& z >= 0 && z < this->layers) // Prevents out of bounds
	{
		if (this->map[x][y][z] != nullptr) // Check if tile is empty
		{
			delete this->map[x][y][z];
			this->map[x][y][z] = nullptr;
		}
	}
}

void TileMap::update()
{

}

void TileMap::render(sf::RenderTarget& target)
{
	for (auto& x : this->map)
		for (auto& y : x)
			for (auto* z : y)
				if (z)
					z->render(target);
}
// #### Functions #### //