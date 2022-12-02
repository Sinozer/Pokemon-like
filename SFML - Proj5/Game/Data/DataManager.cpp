#include "stdafx.h"
#include "DataManager.h"

using namespace std;

// for convenience
//using nlohmann::json = nlohmann::nlohmann::json;



nlohmann::json DataManager::getAll(std::string filePath)
{
	ifstream file(filePath);
	nlohmann::json reader = nlohmann::json::parse(file);

	return reader;
}

/* ################################################## */
/* ################################################## */
/* ################################################## */

//void DataManager::addFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited)
//{
//	string charNumb = to_string(number);
//	nlohmann::json feeders = DataManager::getFeeders();
//	if (feeders.size() == 0 || feeders[charNumb].size() == 0)
//	{
//		feeders[charNumb] = DataManager::templateFeeder(timeC, timeT, quantity, eat, vomited);
//
//		nlohmann::json all = DataManager::getAll();
//		all["feeders"] = feeders;
//		ofstream o("Resources/Data/pokedex.nlohmann::json");
//		o << setw(10) << all << endl;
//	}
//}
//
//void DataManager::modifyFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited)
//{
//	string charNumb = to_string(number);
//	nlohmann::json feeders = DataManager::getFeeders();
//	if (feeders[charNumb].size() == 0)return;
//	feeders[charNumb] = DataManager::templateFeeder(timeC, timeT, quantity, eat, vomited);
//
//	nlohmann::json all = DataManager::getAll();
//	all["feeders"] = feeders;
//	ofstream o("Resources/Data/pokedex.nlohmann::json");
//	o << setw(10) << all << endl;
//}
//
//void DataManager::removeFeeder(int number)
//{
//	string charNumb = to_string(number);
//	nlohmann::json feeders = DataManager::getFeeders();
//	if (feeders[charNumb].size() == 0)return;
//	feeders[charNumb] = {};
//
//	nlohmann::json all = DataManager::getAll();
//	all["feeders"].merge_patch(feeders);
//	ofstream o("Resources/Data/pokedex.nlohmann::json");
//	o << setw(10) << all << endl;
//}
//
//nlohmann::json DataManager::getFeeders()
//{
//	return DataManager::getAll()["feeders"];
//}
//
//void DataManager::addProduct(const char* name, int quantity)
//{
//	nlohmann::json products = DataManager::getProducts();
//	if (products[name] != NULL)
//		return;
//	products[name] = DataManager::templateProduct(quantity);
//
//	nlohmann::json all = DataManager::getAll();
//	all["stock"] = products;
//
//	ofstream o("Resources/Data/pokedex.nlohmann::json");
//	o << setw(10) << all << endl;
//}
//
//void DataManager::modifyProduct(const char* name, int quantity)
//{
//	nlohmann::json products = DataManager::getProducts();
//	if (products[name].size() == 0)return;
//	products[name] = DataManager::templateProduct(quantity);
//
//	nlohmann::json all = DataManager::getAll();
//	all["stock"] = products;
//
//	ofstream o("Resources/Data/pokedex.nlohmann::json");
//	o << setw(10) << all << endl;
//}
//
//void DataManager::removeProduct()
//{
//	/*nlohmann::json products = DataManager::getProducts();
//	if (products[name].size() == 0)return;
//	products[name] = {};
//
//	nlohmann::json all = DataManager::getAll();
//	all["stock"].merge_patch(products);
//	ofstream o("Resources/Data/pokedex.nlohmann::json");
//	o << setw(10) << all << endl;*/
//
//	nlohmann::json pokemons = DataManager::getAll();
//	if (pokemons.size() == 0)return;
//	for (auto& i : pokemons)
//	{
//		//std::cout << i["id"] << std::endl;
//		i["image"].erase("japanese");
//		i["name"].erase("chinese");
//		std::cout << i["name"] << endl;
//	}
//
//
//	/*nlohmann::json all = DataManager::getAll();
//	all.merge_patch(pokemons);*/
//	ofstream o("Resources/Data/pokedex.nlohmann::json");
//	o << setw(2) << pokemons << endl;
//
//
//}
//
//nlohmann::json DataManager::getProducts()
//{
//	return DataManager::getAll()["stock"];
//}
//
//nlohmann::json DataManager::templateFeeder(int timeC, int timeT, int quantity, bool eat, bool vomited)
//{
//	nlohmann::json tempFeeder =
//	{
//		{"timeCreated", timeC}, //time_t
//		{"timeTaken", timeT}, //time_t
//		{"quantity", quantity}, //int
//		{"isEated", eat},
//		{"isVomited", vomited} //bool
//	};
//	return tempFeeder;
//}
//
//nlohmann::json DataManager::templateProduct(int quantity)
//{
//	nlohmann::json tempProduct =
//	{
//		{"quantity", quantity}, //int
//	};
//	return tempProduct;
//}