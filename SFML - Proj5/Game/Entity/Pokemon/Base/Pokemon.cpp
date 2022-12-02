#include "stdafx.h"
#include "Pokemon.h"

// #### PRIVATE #### //

// #### Init Functions #### //
void Pokemon::initVariables()
{
	this->stats = std::map<std::string, int>();
	this->name = "404";
	this->textures = std::map<std::string, sf::Texture>();
	this->description = "NOT LOADED YET";
	this->types = std::vector<std::string>();
	
	this->sprite = sf::Sprite();
	this->thumbnail = sf::Sprite();
}
// #### Init Functions #### //

// #### PRIVATE #### //

// #### Constructor | Destructor #### //
Pokemon::Pokemon()
{
}

Pokemon::Pokemon(std::map<std::string, int> base, std::string name, std::map<std::string, std::string> images, std::string description, std::vector<std::string> types)
{
	this->initVariables();
	this->stats = base;
	this->name = name;
	this->textures["sprite"].loadFromFile(images["sprite"]);
	this->textures["thumbnail"].loadFromFile(images["thumbnail"]);
	this->description = description;
	for (auto i : types)
		this->types.push_back(i);

	this->sprite.setTexture(this->textures["sprite"]);
	this->sprite.setTexture(this->textures["thumbnail"]);
}

Pokemon::~Pokemon()
{
	
}
// #### Constructor | Destructor #### //

// #### Component Functions #### //

// #### Component Functions #### //

// #### Accessors #### //

// #### Accessors #### //

// #### Functions #### //
void Pokemon::update(const float& dt)
{

}
// #### Functions #### //