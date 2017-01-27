#include <iostream>
#include "JsonBox.h"
#include <string>

int main() {
	JsonBox::Value f;
	f.loadFromFile("data2.ort");
	JsonBox::Object o = f.getObject();
	
	for (auto i : o) {
		std::string w = i.first;
		std::cout << w << "\n";
	}
		

	return 0;
};