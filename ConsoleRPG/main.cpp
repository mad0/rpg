#include <iostream>
#include "JsonBox.h"
#include <string>
#include <map>

int main() {
	std::map <std::string, std::string> data;
	JsonBox::Value f;
	f.loadFromFile("data2.ort");
	JsonBox::Object o = f.getObject();
	
	for (auto i : o) {
		std::string z = i.first;
		auto w = i.second;

		std::cout <<w;
	}
		

	return 0;
};