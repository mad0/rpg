#include <iostream>
#include "JsonBox.h"
#include <string>
#include <map>
#include <stack>



class Baza {
public:
	virtual void fun() {
		std::cout << "BAZOWA\n";
	}
	
};

class Pochodna : public Baza {
public:
	void fun() {
		std::cout << "POCHODNA\n";
	}

};

std::stack <Baza*> dane;

Baza* klasa() {
	return dane.top();
}

int main() {
	
	Baza **wsk = new Baza* [4];
	//dane.push(wsk);
	/*std::map <std::string, JsonBox::Value> data;
	JsonBox::Value f;
	f.loadFromFile("data2.ort");
	JsonBox::Object o = f.getObject();
	
	for (auto i : o) {
		std::string z = i.first;
		data[z] = i.second;
	}
	/*for (auto c : data) {
		std::cout <<"Pierwszy: "<< c.first << "\n";
		std::cout << "Drugi: "<<c.second["doors"].getString() << "\n";
	}*/
	//Pochodna *wsk = new Pochodna();
	//wsk->fun();
	//klasa()->fun();
	//std::cout << dane.size() << "\n";
	return 0;
};

