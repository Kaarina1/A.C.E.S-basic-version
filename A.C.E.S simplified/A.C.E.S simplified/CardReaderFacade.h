#pragma once
#include "CardReader.h"
#include <iostream>
#include <string>
using namespace std;
//https://stackoverflow.com/questions/249581/explain-facade-pattern-with-c-example
class CardReaderFacade
{
private: CardReader card_reader_facade;

public: 
	bool card_reader(string card_id, string room_id) {
		bool access = card_reader_facade.check_access(card_id, room_id);
		return access;
	}
};

