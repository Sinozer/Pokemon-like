#pragma once
#include "Game/Data/DataManager.h"
#include "Game/Entity/Pokemon/Base/Pokemon.h"
class PokemonManager
{
private:
	// #### Variables #### //
	std::string jsonPath;

	
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	void initPokemons();
	// #### Init Functions #### //
protected:
	// #### Variables #### //

	// #### Variables #### //
public:
	std::vector<Pokemon*> pokemons;

	// #### Constructor | Destructor #### //
	PokemonManager(std::string jsonPokemonsPath);						// Class constructor
	virtual ~PokemonManager();				// Class destructor
	// #### Constructor | Destructor #### //

	// #### Component Functions #### //

	// #### Component Functions #### //

	// #### Accessors #### //

	// #### Accessors #### //

	// #### Functions #### //
	void update(const float& dt);
	// #### Functions #### //
};

