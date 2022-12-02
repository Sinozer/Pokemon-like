#pragma once
#include "Layer.h"
#include "Game/Data/DataManager.h"
#include "Game/Entity/List/Player/Player.h"

class Map
{
private:
	// #### Variables #### //
	std::string jsonPath;

	sf::Vector2i maxGrid;

	Player* player;
	sf::IntRect radius;

	std::map<std::map<std::string, int>, sf::Texture> textures;	// [[sheetPath, firstId], texture*]
	std::vector<Layer*> layers;

	float keyTime;
	float keyTimeMax;
	// #### Variables #### //

	// #### Init Function #### //
	void initVariables();
	void initTextures();
	void initLayers();
	// #### Init Function #### //
public:
	// #### Constructor | Destructor #### //
	Map(Player* player, std::string jsonMapPath);		// Class constructor
	virtual ~Map();		// Class destructor
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const bool getKeyTime();
	void updateKeyTime(const float& dt);
	// #### Accessors #### //

	// #### Modifiers #### //
	
	// #### Modifiers #### //

	// #### Functions #### //
	void update(const float& dt);
	void render(sf::RenderTarget& target);
	// #### Functions #### //
};

