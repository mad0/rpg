#include <iostream>
#include "JsonBox.h"
#include <string>
#include <map>
#include <stack>
#include <memory>



class Baza {
public:
	Baza() {
		std::cout << "UTWORZENIE BAZOWA\n";
		//++ile;
		//std::cout << "POCHODNA: " << ile << "\n";
	}
	~Baza() {
		std::cout << "USUNIECIE: BAZOWA\n";
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
		std::cout << "UTWORZENIE POCHODNA\n";
		++ile;
	}
	
	~Pochodna() {
		std::cout << "USUNIECIE: Pochodna\n";
	}

	void fun() {
		std::cout << "POCHODNA: Obiekt nr: " << t << "\n";
	}

};

std::stack<Baza*> dane;

Baza* run() {
	std::cout << "Ilosc obiektow na stosie: " << dane.size() << "\n";
	return dane.top();
}

int Pochodna::ile = 0;

int main() {
	
	{
		Baza *p1(new Pochodna("1"));
		Baza *p2(new Pochodna("2"));
		dane.push(p1);
		dane.push(p2);
		run();
		delete dane.top();
		dane.pop();
		dane.top()->fun();

	}

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
	//dane.top()->fun();
	return 0;
};

