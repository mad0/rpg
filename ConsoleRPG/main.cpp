#include <iostream>
#include "JsonBox.h"
#include <string>
#include <map>
#include <stack>



class Baza {
public:
	Baza() {
		//++ile;
		//std::cout << "POCHODNA: " << ile << "\n";
	}
	virtual void fun() {
		std::cout << "BAZOWA\n";
	}
	
};

class Pochodna : public Baza {
private:
	std::string t;
public:
	static int ile;
	Pochodna(const std::string &z) : t(z) {
		++ile;
	}
	
	void fun() {
		std::cout << "POCHODNA: Obiekt nr: " << t << "\n";
	}

};

std::stack <Baza*> dane;

Baza* klasa() {
	std::cout << "Ilosc obiektow na stosie: " << dane.size() << "\n";
	return dane.top();
}

int Pochodna::ile = 0;

int main() {
	
	Baza **wsk = new Baza* [4];
	//Baza *wsk = new Pochodna();
	wsk[0] = new Pochodna("a");
	wsk[1] = new Pochodna("b");
	wsk[2] = new Pochodna("c");
	wsk[3] = new Pochodna("d");
	dane.push(wsk[0]);
	dane.push(wsk[1]);
	dane.push(wsk[2]);
	dane.push(wsk[3]);
	dane.pop();
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
	//wsk->fun();
	/*wsk[0]->fun();
	wsk[1]->fun();
	wsk[2]->fun();
	wsk[3]->fun();
	*/
	dane.top()->fun();
	return 0;
};

