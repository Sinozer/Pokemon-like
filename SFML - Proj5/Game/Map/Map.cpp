#include "stdafx.h"
#include "Map.h"

// #### Init Function #### //
void Map::initVariables()
{
	this->radius = sf::IntRect(-1, -1, 1, 1);
	this->maxGrid = sf::Vector2i(DataManager::getAll(this->jsonPath)["height"],
		DataManager::getAll(this->jsonPath)["width"]);

	this->keyTimeMax = 2.f;
	this->keyTime = 0.f;
}

void Map::initTextures()
{
	std::map<std::string, int> temp;

	for (auto i = 0; i < DataManager::getAll(this->jsonPath)["tilesets"].size(); i++)
	{
		temp[DataManager::getAll(this->jsonPath)["tilesets"][i]["source"]] = DataManager::getAll(this->jsonPath)["tilesets"][i]["firstgid"];

		if (!this->textures[temp].loadFromFile(DataManager::getAll(this->jsonPath)["tilesets"][i]["source"]))
			throw("ERROR::MAP: FAILED TO LOAD TEXTURE");
	}
}

void Map::initLayers()
{
	for (auto i = 0; i < DataManager::getAll(this->jsonPath)["layers"].size(); i++)
	{
		this->layers.push_back(new Layer(this->textures,
			DataManager::getAll(this->jsonPath)["layers"][i]["width"],
			DataManager::getAll(this->jsonPath)["layers"][i]["height"],
			DataManager::getAll(this->jsonPath)["layers"][i]["collide"],
			DataManager::getAll(this->jsonPath)["layers"][i]["spawn"],
			DataManager::getAll(this->jsonPath)["layers"][i]["data"]));
	}
}
// #### Init Function #### //

// #### Constructor | Destructor #### //
Map::Map(Player* player, std::string jsonMapPath) : player(player)
{
	this->jsonPath = jsonMapPath;
	this->initVariables();
	this->initTextures();
	this->initLayers();
}

Map::~Map()
{
	for (auto& i : this->layers)
		delete i;
}
// #### Constructor | Destructor #### //

// #### Accessors #### //
const bool Map::getKeyTime()
{
	if (this->keyTime >= this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}
	return false;
}

void Map::updateKeyTime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
		this->keyTime += 5.f * dt;
}
// #### Accessors #### //

// #### Modifiers #### //

// #### Modifiers #### //

// #### Functions #### //
void Map::update(const float& dt)
{
	this->updateKeyTime(dt);

	for (auto& i : this->layers)
	{
		if (this->player && i->isColliding() || i->isSpawning())
		{
			this->radius.left = this->player->getPosition().x / 64 - 1;
			if (this->radius.left < 0)
				this->radius.left = 0;
			else if (this->radius.left > maxGrid.x)
				this->radius.left = maxGrid.x;
			this->radius.top = this->player->getPosition().y / 64 - 1;
			if (this->radius.top < 0)
				this->radius.top = 0;
			else if (this->radius.top > maxGrid.y)
				this->radius.top = maxGrid.y;
			this->radius.width = this->player->getPosition().x / 64 + 3;
			if (this->radius.width < 0)
				this->radius.width = 0;
			else if (this->radius.width > maxGrid.x)
				this->radius.width = maxGrid.x;
			this->radius.height = this->player->getPosition().y / 64 + 3;
			if (this->radius.height < 0)
				this->radius.height = 0;
			else if (this->radius.height > maxGrid.y)
				this->radius.height = maxGrid.y;

			for (auto x = this->radius.left; x < this->radius.width; x++)
				for (auto y = this->radius.top; y < this->radius.height; y++)
					if (i->getTiles()[x][y] && i->getTiles()[x][y]->getShape().getGlobalBounds().intersects(this->player->getHitbox().getGlobalBounds()))
					{
						if (i->isColliding())
						{
							// DOWN
							if (this->player->getMovementComponent()->getState(5))
								if (this->player->getHitbox().getGlobalBounds().top < i->getTiles()[x][y]->getShape().getGlobalBounds().top
									&& this->player->getHitbox().getGlobalBounds().top + this->player->getHitbox().getGlobalBounds().height < i->getTiles()[x][y]->getShape().getGlobalBounds().top + i->getTiles()[x][y]->getShape().getGlobalBounds().height
									&& this->player->getHitbox().getGlobalBounds().left < i->getTiles()[x][y]->getShape().getGlobalBounds().left + i->getTiles()[x][y]->getShape().getGlobalBounds().width
									&& this->player->getHitbox().getGlobalBounds().left + this->player->getHitbox().getGlobalBounds().width > i->getTiles()[x][y]->getShape().getGlobalBounds().left)
								{
									this->player->getVelocity().y = 0;
									this->player->setPosition(this->player->getPosition().x, i->getTiles()[x][y]->getShape().getGlobalBounds().top - this->player->getHitbox().getGlobalBounds().height - 31);
								}

							// UP
							if (this->player->getMovementComponent()->getState(4))
								if (this->player->getHitbox().getGlobalBounds().top > i->getTiles()[x][y]->getShape().getGlobalBounds().top
									&& this->player->getHitbox().getGlobalBounds().top + this->player->getHitbox().getGlobalBounds().height > i->getTiles()[x][y]->getShape().getGlobalBounds().top + i->getTiles()[x][y]->getShape().getGlobalBounds().height
									&& this->player->getHitbox().getGlobalBounds().left < i->getTiles()[x][y]->getShape().getGlobalBounds().left + i->getTiles()[x][y]->getShape().getGlobalBounds().width
									&& this->player->getHitbox().getGlobalBounds().left + this->player->getHitbox().getGlobalBounds().width > i->getTiles()[x][y]->getShape().getGlobalBounds().left
									)
								{
									this->player->getVelocity().y = 0;
									this->player->setPosition(this->player->getPosition().x, i->getTiles()[x][y]->getShape().getGlobalBounds().top + i->getTiles()[x][y]->getShape().getGlobalBounds().height - 32);
								}

							// RIGHT
							if (this->player->getMovementComponent()->getState(3))
								if (this->player->getHitbox().getGlobalBounds().left < i->getTiles()[x][y]->getShape().getGlobalBounds().left
									&& this->player->getHitbox().getGlobalBounds().left + this->player->getHitbox().getGlobalBounds().width < i->getTiles()[x][y]->getShape().getGlobalBounds().left + i->getTiles()[x][y]->getShape().getGlobalBounds().width
									&& this->player->getHitbox().getGlobalBounds().top < i->getTiles()[x][y]->getShape().getGlobalBounds().top + i->getTiles()[x][y]->getShape().getGlobalBounds().height
									&& this->player->getHitbox().getGlobalBounds().top + this->player->getHitbox().getGlobalBounds().height > i->getTiles()[x][y]->getShape().getGlobalBounds().top
									)
								{
									this->player->getVelocity().x = 0;
									this->player->setPosition(i->getTiles()[x][y]->getShape().getGlobalBounds().left - i->getTiles()[x][y]->getShape().getGlobalBounds().width - 8, this->player->getPosition().y);
								}

							// LEFT
							if (this->player->getMovementComponent()->getState(2))
								if (this->player->getHitbox().getGlobalBounds().left > i->getTiles()[x][y]->getShape().getGlobalBounds().left
									&& this->player->getHitbox().getGlobalBounds().left + this->player->getHitbox().getGlobalBounds().width > i->getTiles()[x][y]->getShape().getGlobalBounds().left + i->getTiles()[x][y]->getShape().getGlobalBounds().width
									&& this->player->getHitbox().getGlobalBounds().top < i->getTiles()[x][y]->getShape().getGlobalBounds().top + i->getTiles()[x][y]->getShape().getGlobalBounds().height
									&& this->player->getHitbox().getGlobalBounds().top + this->player->getHitbox().getGlobalBounds().height > i->getTiles()[x][y]->getShape().getGlobalBounds().top
									)
								{
									this->player->getVelocity().x = 0;
									this->player->setPosition(i->getTiles()[x][y]->getShape().getGlobalBounds().left + i->getTiles()[x][y]->getShape().getGlobalBounds().width - 15, this->player->getPosition().y);
								}
						}
						else if (i->isSpawning() && !this->player->getCombatComponent()->isCombat() && this->getKeyTime())
						{
							// RANDOM LAUNCH COMBAT
							//srand(time(NULL));
							int random = rand() % 7;
							std::cout << random << std::endl;
							if (random == 3)
							{
								std::cout << "COMBAT" << std::endl;
								this->player->getCombatComponent()->startCombat();
							}
								
						}
					}

		}
		//i->update(); NOTHING TO DO
	}
}

void Map::render(sf::RenderTarget& target)
{
	for (auto& i : this->layers)
		i->render(target);
}
// #### Functions #### //