#pragma once
#include <iostream>
#include <string>
using namespace std;
//https://www.modernescpp.com/index.php/the-facade-pattern/
class CardReader
{
public:
	bool check_access(string card_id, string door_id);
	//To do later bool check_door(string door_id);
private:
	bool verify(int card_id);
	bool authenticate(string s_card_id, string door_id);
	bool authorise(string s_card_id, string door_id);
};

