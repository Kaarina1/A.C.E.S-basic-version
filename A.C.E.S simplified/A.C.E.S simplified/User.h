#pragma once
#include <iostream>
#include <string>
using namespace std;
//https://www.w3schools.com/cpp/cpp_structs.asp
class User
{
	string card_id;
	string first_name;
	string last_name;
	string role;

private:
	string get_card();
};

