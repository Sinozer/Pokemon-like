#pragma once

using json = nlohmann::json;

class DataManager
{
public:
	void static addFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static modifyFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static removeFeeder(int number);
	json static getFeeders(); //return Feeder


	void static addProduct(const char* name, int quantity);
	void static modifyProduct(const char* name, int quantity);
	void static removeProduct(const char* name);
	json static getProducts(); //return Product

	json static getAll(); //retun all data

	json static templateFeeder(int timeC, int timeT, int quantity, bool eat, bool vomited); //data template of feeder
	json static templateProduct(int quantity); //data tamplate of product
};