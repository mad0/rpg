#include <iostream>
#include "JsonBox.h"
#include <string>
#include <map>

int main() {
	std::map <std::string, JsonBox::Value> data;
	JsonBox::Value f;
	f.loadFromFile("data2.ort");
	JsonBox::Object o = f.getObject();
	
	for (auto i : o) {
		std::string z = i.first;
		data[z] = i.second;
	}
	for (auto c : data) {
		std::cout <<"Pierwszy: "<< c.first << "\n";
		std::cout << "Drugi: "<<c.second["doors"].getString() << "\n";
	}
		

	return 0;
};