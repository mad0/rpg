#include <iostream>
#include "JsonBox.h"
#include <string>

int main() {
	JsonBox::Value f;
	f.loadFromFile("data.ort");
	JsonBox::Object o = f.getObject();
	
	for (auto i : o) {
		std::string w = i.first;
		auto g = i.second;
		std::cout << typeid(g).name() << "\n";
		//std::cout << w << "\n";
	}
		

	return 0;
};