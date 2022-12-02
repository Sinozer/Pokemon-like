#include "stdafx.h"
#include "CombatComponent.h"

// #### Init Function #### //
void CombatComponent::initVariables()
{
	this->combat = false;
}
// #### Init Function #### //

// #### Constructor | Destructor #### //
CombatComponent::CombatComponent()
{
	this->initVariables();
}

CombatComponent::~CombatComponent()
{

}
// #### Constructor | Destructor #### //

// #### Accessors #### //
const bool CombatComponent::isCombat() const
{
	return this->combat;
}

Pokemon CombatComponent::getAlly()
{
	return this->ally;
}

Pokemon CombatComponent::getOpponent()
{
	return this->opponent;
}
// #### Accessors #### //

// #### Functions #### //
void CombatComponent::initPokemons(std::vector<Pokemon*>& pokemons)
{
	this->pokemons = pokemons;
	this->ally = *pokemons[0];
}

void CombatComponent::startCombat()
{
	this->combat = true;

	srand(time(NULL));
	int random = rand() % this->pokemons.size();
	
	this->opponent = *this->pokemons[random];

	std::cout << "Ally: " << this->ally.name << std::endl;
	std::cout << "Opponent: " << this->opponent.name << std::endl;
}

void CombatComponent::endCombat()
{
	this->combat = false;
}

void CombatComponent::update(const float& dt)
{
	if (this->combat)	// Update only if combat is launched
	{
		
	}
}

void CombatComponent::render(sf::RenderTarget& target)
{
	if (this->combat)	// Render only if combat is launched
	{
		
	}
}
// #### Functions #### //