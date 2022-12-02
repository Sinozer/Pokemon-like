#include "stdafx.h"
#include "PokemonManager.h"

// #### PRIVATE #### //

// #### Init Functions #### //
void PokemonManager::initVariables()
{

}

void PokemonManager::initPokemons()
{
	std::cout << DataManager::getAll(this->jsonPath).size() << std::endl;
	for (auto i = 0; i < 50; i++)
	{		this->pokemons.push_back(new Pokemon(DataManager::getAll(this->jsonPath)[i]["base"],
			DataManager::getAll(this->jsonPath)[i]["name"],
			DataManager::getAll(this->jsonPath)[i]["image"],
			DataManager::getAll(this->jsonPath)[i]["description"],
			DataManager::getAll(this->jsonPath)[i]["type"]));
	}
}
// #### Init Functions #### //

// #### PRIVATE #### //

// #### Constructor | Destructor #### //
PokemonManager::PokemonManager(std::string jsonPokemonsPath)
{
	this->jsonPath = jsonPokemonsPath;
	this->initVariables();
	this->initPokemons();
}

PokemonManager::~PokemonManager()
{

}
// #### Constructor | Destructor #### //

// #### Component Functions #### //

// #### Component Functions #### //

// #### Accessors #### //

// #### Accessors #### //

// #### Functions #### //
void PokemonManager::update(const float& dt)
{

}
// #### Functions #### //