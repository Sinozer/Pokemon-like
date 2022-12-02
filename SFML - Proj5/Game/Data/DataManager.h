#pragma once

//using json = nlohmann::json;

class DataManager
{
public:
	nlohmann::json static getAll(std::string filePath); //retun all data

	/* ################################################## */
	/* ################################################## */
	/* ################################################## */

	void static addFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static modifyFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static removeFeeder(int number);
	nlohmann::json static getFeeders(); //return Feeder


	void static addProduct(const char* name, int quantity);
	void static modifyProduct(const char* name, int quantity);
	void static removeProduct();
	nlohmann::json static getProducts(); //return Product

	nlohmann::json static templateFeeder(int timeC, int timeT, int quantity, bool eat, bool vomited); //data template of feeder
	nlohmann::json static templateProduct(int quantity); //data tamplate of product
};