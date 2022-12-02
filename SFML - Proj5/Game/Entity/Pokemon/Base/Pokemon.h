#pragma once

class Pokemon
{
private:
	// #### Variables #### //
	
	// #### Variables #### //

	// #### Init Functions #### //
	void initVariables();
	// #### Init Functions #### //
protected:
	// #### Variables #### //
	
	// #### Variables #### //
public:
	std::map<std::string, int> stats;
	std::string name;
	std::map<std::string, sf::Texture> textures;
	std::string description;
	std::vector<std::string> types;


	sf::Sprite sprite;
	sf::Sprite thumbnail;

	// #### Constructor | Destructor #### //
	Pokemon();
	Pokemon(std::map<std::string, int> stats, std::string name, std::map<std::string, std::string> images, std::string description, std::vector<std::string> types);	// Class constructor
	virtual ~Pokemon();				// Class destructor
	// #### Constructor | Destructor #### //

	// #### Component Functions #### //
	
	// #### Component Functions #### //

	// #### Accessors #### //
	
	// #### Accessors #### //

	// #### Functions #### //
	void update(const float& dt);
	// #### Functions #### //
};

