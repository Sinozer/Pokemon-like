#include "stdafx.h"
#include "Layer.h"

// #### Init Function #### //
void Layer::initVariables()
{
	this->size = sf::Vector2u(0, 0);
	this->collide = false;
	this->spawn = false;
}

void Layer::initTiles()
{
	this->tiles = std::vector<std::vector<Tile*>>(this->size.x, std::vector<Tile*>(this->size.y));

	for (auto y = 0; y < this->size.y; y++)
	{
		for (auto x = 0; x < this->size.x; x++)
		{
			if (this->data[this->size.x * y + x] != 0)
			{
				for (auto& i : this->textures)
					for (auto& j : i.first)
						if (this->data[this->size.x * y + x] < j.second)
							continue;
						else
						{
							float xRect = this->data[this->size.x * y + x] - 1;
							xRect = static_cast<int>(xRect) % static_cast<int>(i.second.getSize().x / 32);
							xRect = xRect * 32;
							//int yRect = ceil((this->data[this->size.x * y + x] / i.second.getSize().y / 32) * 32);
							//float yRect = this->data[this->size.x * y + x];
							float yRect = this->data[this->size.x * y + x] - 1;
							yRect = floor(yRect / (i.second.getSize().x / 32));
							yRect = yRect * 32;
							/*if (xRect == -32)
							{
								xRect = 224;
								yRect -= 32;
							}*/
							this->tiles[x][y] = new Tile(x, y, 64, &i.second, sf::IntRect(
								xRect,
								yRect,
								32, 32));
						}
			}
			else
			{
				this->tiles[x][y] = nullptr;
			}
		}
	}
}
// #### Init Function #### //

// #### Constructor | Destructor #### //
Layer::Layer(std::map<std::map<std::string, int>, sf::Texture>& textures, unsigned width, unsigned height, bool collide, bool spawn, std::vector<int> data)
{
	this->initVariables();

	this->textures = textures;
	this->size.x = width;
	this->size.y = height;
	this->collide = collide;
	this->spawn = spawn;
	this->data = data;

	this->initTiles();
}

Layer::~Layer()
{
	for (auto& i : this->tiles)
		for (auto& j : i)
			delete j;
}
// #### Constructor | Destructor #### //

// #### Accessors #### //

const std::vector<std::vector<Tile*>> Layer::getTiles() const
{
	return this->tiles;
}

// #### Accessors #### //
const bool Layer::isColliding() const
{
	return this->collide;
}

const bool Layer::isSpawning() const
{
	return this->spawn;
}
// #### Modifiers #### //

// #### Modifiers #### //

// #### Functions #### //
void Layer::update()
{
	for (auto& i : this->tiles)
		for (auto& j : i)
			j->update();
}

void Layer::render(sf::RenderTarget& target)
{
	for (auto& i : this->tiles)
		for (auto& j : i)
			if (j && j->getShape().getTextureRect().left < target.getSize().x && j->getShape().getTextureRect().top < target.getSize().y)
				j->render(target);
}
// #### Functions #### //