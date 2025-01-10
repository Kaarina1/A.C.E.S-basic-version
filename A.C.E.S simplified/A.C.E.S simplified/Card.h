#pragma once
#include <iostream>
#include <string>
using namespace std;
class Card
{	
protected:
	string generate_id();
private:
	string card_id= generate_id();
public:
	string getCardID() {
		return card_id;
	}
};


