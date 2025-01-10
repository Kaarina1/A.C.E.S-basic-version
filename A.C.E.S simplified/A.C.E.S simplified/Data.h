#pragma once
#include <iostream>
#include <string>
using namespace std;
class Data
{
public:
	void get_logs();
	void get_users();
	void get_rooms();

	bool check_card(string card_id);
	bool check_door(string door_id);
	void log_access(string card_id, string door_id, bool authorised);
	bool compare_ids(string card_id, string door_id);

	
	void add_user(string first_name, string last_name, string role);
	void add_room(string room_id, string room_type, string room_state);
};

//Logs File
//Room, Room  Type, State, CardID, First Name, Last Name, Role, Decision

//Rooms Log
//Room, Lecture, State

//Users File
//CardID, (First Name, Last Name), Role, (Rooms), (States) 