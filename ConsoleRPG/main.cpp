#include <iostream>
#include "JsonBox.h"
#include <string>
#include <map>
#include <stack>
#include <memory>



class Baza {
public:
	Baza() {
		std::cout << "Utworzono obiekt BAZA\n";
	}
	~Baza() {
		std::cout << "Uusunieto obiekt BAZA\n";
	}
	virtual void fun() {
		std::cout << "BAZOWA\n";
	}
	
};

class Pochodna : public Baza {
public:
	Pochodna() {
		std::cout << "Utworzono obiekt POCHODNA\n";
	}
	~Pochodna() {
		std::cout << "Uusunieto obiekt POCHODNA\n";
	}
	void fun() {
		std::cout << "POCHODNA\n";
	}

};
std::stack <std::unique_ptr<Baza>> dane;

/*std::unique_ptr<Baza> klasa() {
	return dane.top();
	//return dane->top();
}*/

int main() {
	
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
	{
		std::unique_ptr<Baza> p1(new Pochodna);
		p1->fun();
		dane.push(std::move(p1));
		//std::cout << typeid(p1).name() << "\n";
		//dane.push_back(std::move(p1));
		// dane[0]->fun();
		std::cout << dane.size() << "\n";
		dane.pop();
		std::cout << dane.size() << "\n";
		std::cout << "KONIEC\n";

		
	}
	
	return 0;
};

