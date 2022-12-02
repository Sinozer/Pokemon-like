#pragma once
#include "Game/Entity/Pokemon/Base/Pokemon.h"
class CombatComponent
{
private:
	// #### Variables #### //
	bool combat;

	Pokemon ally;
	Pokemon opponent;

	std::vector<Pokemon*> pokemons;
	// #### Variables #### //

	// #### Init Function #### //
	void initVariables();
	// #### Init Function #### //
public:
	// #### Constructor | Destructor #### //
	CombatComponent();
	virtual ~CombatComponent();
	// #### Constructor | Destructor #### //

	// #### Accessors #### //
	const bool isCombat() const;
	Pokemon getAlly();
	Pokemon getOpponent();
	// #### Accessors #### //

	// #### Functions #### //
	void initPokemons(std::vector<Pokemon*>& pokemons);

	void startCombat();
	void endCombat();

	void update(const float& dt);
	void render(sf::RenderTarget& target);
	// #### Functions #### //
};