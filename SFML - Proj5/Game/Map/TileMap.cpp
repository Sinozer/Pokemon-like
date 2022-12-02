#include "stdafx.h"
#include "TileMap.h"

// #### Init Function #### //
void TileMap::initTexture()
{
	/*sf::Texture* temp = new sf::Texture;
	if (!temp->loadFromFile("Resources/Images/Tiles/grounds.png"))
		throw("ERROR::TILEMAP: FAILED TO LOAD IMAGE");
	this->sheets.push_back(temp);*/

	if (!this->sheets["DECORATIONS"].loadFromFile("Resources/Images/Tiles/decorations.png"))
		throw("ERROR::TILEMAP: FAILED TO LOAD IMAGE");

	if (!this->sheets["GROUNDS"].loadFromFile("Resources/Images/Tiles/grounds.png"))
		throw("ERROR::TILEMAP: FAILED TO LOAD IMAGE");

	if (!this->sheets.empty())
		this->selectedSheet = &sheets.begin()->second;
}
// #### Init Function #### //

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

	this->initTexture();
	if (!this->tileTextureSheet.loadFromFile("Resources/Images/Tiles/grounds.png"/*, sf::IntRect(0, 0, 8*32, 3*32 )*/))
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
const sf::Texture* TileMap::getTileSheet() const
{
	return this->selectedSheet;
}
// #### Accessors #### //

// #### Modifiers #### //
void TileMap::increaseTextureSet()
{
	for (auto i = this->sheets.begin(); i != this->sheets.end(); i++)
		if (&i->second == this->selectedSheet && i.operator!=(--this->sheets.end()))
		{
			this->selectedSheet = &((++i)->second);
			break;
		}
}

void TileMap::decreaseTextureSet()
{
	for (auto i = this->sheets.begin(); i != this->sheets.end(); i++)
		if (&i->second == this->selectedSheet && i.operator!=(this->sheets.begin()))
		{
			this->selectedSheet = &((--i)->second);
			break;
		}
}
// #### Modifiers #### //

// #### Functions #### //
//void TileMap::addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& textureRect)
//{
//	if (x >= 0 && x < this->maxSize.x
//		&& y >= 0 && y < this->maxSize.y
//		&& z >= 0 && z < this->layers) // Prevents out of bounds
//	{
//		if (this->map[x][y][z] == nullptr) // Check if tile is empty
//			this->map[x][y][z] = new Tile(x, y, this->gridSizeF, *this->selectedSheet, textureRect);
//	}
//}

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