#pragma once
#include "Tile.h"

class Layer
{
private:
	// #### Variables #### //
	sf::Vector2u size;

	std::vector<int> data;

	std::map<std::map<std::string, int>, sf::Texture> textures;
	std::vector<std::vector<Tile*>> tiles;

	bool collide;
	bool spawn;
	// #### Variables #### //

	// #### Init Function #### //
	void initVariables();
	void initTiles();
	// #### Init Function #### //
public:
	// #### Constructor | Destructor #### //
	Layer(std::map<std::map<std::string, int>, sf::Texture>& textures, unsigned width, unsigned height, bool collide, bool spawn, std::vector<int> data);		// Class constructor
	virtual ~Layer();		// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const std::vector<std::vector<Tile*>> getTiles() const;
	const bool isColliding() const;
	const bool isSpawning() const;
	// #### Accessors #### //

	// #### Modifiers #### //

	// #### Modifiers #### //

	// #### Functions #### //
	void update();
	void render(sf::RenderTarget& target);
	// #### Functions #### //
};

