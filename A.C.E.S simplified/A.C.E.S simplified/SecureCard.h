#pragma once
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

class SecureCard:Card
{
private:
	string secure_card_id();
	string card_id = secure_card_id();
	
public: 
	string getSecureCardID()
	{
		return card_id;
	};
};

