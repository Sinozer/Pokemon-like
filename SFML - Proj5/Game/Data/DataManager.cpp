#include "stdafx.h"
#include "DataManager.h"

using namespace std;

// for convenience
using json = nlohmann::json;

void DataManager::addFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited)
{
	string charNumb = to_string(number);
	json feeders = DataManager::getFeeders();
	if (feeders.size() == 0 || feeders[charNumb].size() == 0)
	{
		feeders[charNumb] = DataManager::templateFeeder(timeC, timeT, quantity, eat, vomited);

		json all = DataManager::getAll();
		all["feeders"] = feeders;
		ofstream o("Resources/Data/pokedex.json");
		o << setw(10) << all << endl;
	}	
}

void DataManager::modifyFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited)
{
	string charNumb = to_string(number);
	json feeders = DataManager::getFeeders();
	if (feeders[charNumb].size() == 0 )return;
	feeders[charNumb] = DataManager::templateFeeder(timeC, timeT, quantity, eat, vomited);

	json all = DataManager::getAll();
	all["feeders"] = feeders;
	ofstream o("Resources/Data/pokedex.json");
	o << setw(10) << all << endl;
}

void DataManager::removeFeeder(int number)
{
	string charNumb = to_string(number);
	json feeders = DataManager::getFeeders();
	if (feeders[charNumb].size() == 0)return;
	feeders[charNumb] = {};

	json all = DataManager::getAll();
	all["feeders"].merge_patch(feeders);
	ofstream o("Resources/Data/pokedex.json");
	o << setw(10) << all << endl;
}

json DataManager::getFeeders()
{
	return DataManager::getAll()["feeders"];
}

void DataManager::addProduct(const char* name, int quantity)
{
	json products = DataManager::getProducts();
	if (products[name] != NULL)
		return;
	products[name] = DataManager::templateProduct(quantity);

	json all = DataManager::getAll();
	all["stock"] = products;

	ofstream o("Resources/Data/pokedex.json");
	o << setw(10) << all << endl;
}

void DataManager::modifyProduct(const char* name, int quantity)
{
	json products = DataManager::getProducts();
	if (products[name].size() == 0 )return;
	products[name] = DataManager::templateProduct(quantity);

	json all = DataManager::getAll();
	all["stock"] = products;

	ofstream o("Resources/Data/pokedex.json");
	o << setw(10) << all << endl;
}

void DataManager::removeProduct(const char* name)
{
	json products = DataManager::getProducts();
	if (products[name].size() == 0)return;
	products[name] = {};

	json all = DataManager::getAll();
	all["stock"].merge_patch(products);
	ofstream o("Resources/Data/pokedex.json");
	o << setw(10) << all << endl;
}

json DataManager::getProducts()
{
	return DataManager::getAll()["stock"];
}

json DataManager::getAll()
{
	ifstream file("Resources/Data/pokedex.json");
	json reader = json::parse(file);

	return reader;
}

json DataManager::templateFeeder(int timeC, int timeT, int quantity, bool eat, bool vomited)
{
	json tempFeeder =
	{
		{"timeCreated", timeC}, //time_t
		{"timeTaken", timeT}, //time_t
		{"quantity", quantity}, //int
		{"isEated", eat},
		{"isVomited", vomited} //bool
	};
	return tempFeeder;
}

json DataManager::templateProduct(int quantity)
{
	json tempProduct =
	{
		{"quantity", quantity}, //int
	};
	return tempProduct;
}