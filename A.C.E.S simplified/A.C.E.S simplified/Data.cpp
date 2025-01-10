#include "Data.h"
#include "Card.h"
#include "SecureCard.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
//https://cplusplus.com/forum/beginner/248914/#google_vignette

void Data::get_logs() {
	string log_data;

	ifstream MyReadFile("Logs.txt");

	while (getline(MyReadFile, log_data)) {
		cout << " Room ID | Card ID | Descision";
		// Output the text from the file
		cout << log_data <<"\n";
	}
}

void Data::get_users() {
	
	ifstream user_file("Users.txt");
	if (user_file.fail()) {
		cout << "No user file found\n";
	}
	else {
		string data_piece;
		vector<string> data_pieces;
		while (user_file >> data_piece) {
			data_pieces.push_back(data_piece);
		}
		int place = 0;
		cout << "CARD ID | First Name | Last Name | Role\n";
		for (string data : data_pieces) {
			cout << data << " ";
			if (place == 3) {
				place = 0;
				cout << "\n";
			}
			else {
				place++;
			}
		}
	}
}

void Data::get_rooms() {
	string room_data;

	ifstream rooms_file("Rooms.txt");
	if (rooms_file.fail()) {
		cout << "No user file found\n";
	}
	else {
		cout << "Room ID | Room Type | Room State\n";
		while (getline(rooms_file, room_data)) {

			// Output the text from the file
			cout << room_data << "\n";
		}
	}
	
}

bool Data::check_card(string card_id) {
	ifstream user_file("Users.txt");
	string data_piece;
	vector<string> data_pieces;
	while (user_file >> data_piece) {
		data_pieces.push_back(data_piece);
	}

	for (string data : data_pieces) {
		if (data==card_id) {
			return true;
		}
	}
}

bool Data::check_door(string door_id) {
	ifstream room_file("Rooms.txt");
	string data_piece;
	vector<string> data_pieces;
	while (room_file >> data_piece) {
		data_pieces.push_back(data_piece);
	}
	for (string data : data_pieces) {
		if (data == door_id) {
			return true;
		}
	}
}

bool Data::compare_ids(string card_id, string door_id){
//Get Room Data
	ifstream room_file("Rooms.txt");
	string room_data_piece;
	vector<string> room_data_pieces;
	while (room_file >> room_data_piece) {
		room_data_pieces.push_back(room_data_piece);
	}
	bool b_room_type = false;
	bool b_room_state = false;
	string s_room_type, s_room_state;
	for (string data : room_data_pieces) {
		
		if (b_room_state) {
			s_room_state = data;
			b_room_state = false;
		}

		if (b_room_type) {
			s_room_type = data;
			b_room_type = false;
			b_room_state = true;
		}

		if (data == door_id) {
			b_room_type = true;
		}
	}
//Get User Data
	ifstream user_file("Users.txt");
	string user_data_piece;
	vector<string> user_data_pieces;
	while (user_file >> user_data_piece) {
		user_data_pieces.push_back(user_data_piece);
	}
	bool b_user_role=false;
	int count=0;
	string s_user_role;

	for (string data : user_data_pieces) {
		if (b_user_role) {
			count ++;
		}
		if (data == card_id) {
			b_user_role = true;
			count = 1;
		}
		if (count == 4) {
			s_user_role = data;
		}
	}

//Get User states and rooms
	vector<string> user_allowed_rooms;
	vector<string> user_allowed_states;
	
	if (s_user_role == "Manager" || s_user_role=="Security" || s_user_role == "Emergency") {
		user_allowed_rooms.push_back("All");
		if (s_user_role == "Manager") {
			user_allowed_states.push_back("N");
		}
		else if (s_user_role == "Security"){
			user_allowed_states.push_back("All");
		}
		else {
			user_allowed_states.push_back("E");
		}
	}
	else if (s_user_role == "Lecturer" || s_user_role == "Cleaner") {
		user_allowed_rooms.push_back("Lecture");
		user_allowed_rooms.push_back("Teaching");
		user_allowed_rooms.push_back("Staff");
		user_allowed_states.push_back("N");
	}
	else{
		user_allowed_states.push_back("N");
		if (s_user_role == "Student") {
			user_allowed_rooms.push_back("Lecture");
			user_allowed_rooms.push_back("Teaching");
		}
		else {
			user_allowed_rooms.push_back("Lecture");
		}
	}
	bool authorised_room = false;
	bool authorised_state = false;

	for (string user_room : user_allowed_rooms) {
		if (s_room_type == user_room || user_room=="All") {
			authorised_room = true;
		}
	}
	for (string user_state : user_allowed_states) {
		if (s_room_state == user_state || user_state == "All") {
			authorised_state = true;
		}
	}

	if (authorised_room && authorised_state) {
		return true;
	}
	else {
		return false;
	}

}

void Data::log_access(string card_id, string door_id, bool authorised){
	string descision;
	if (authorised) {
		descision = "Authorised";
	}
	else {
		descision = "Unauthorised";
	}
	string log_info = "\n" + card_id + " " + door_id + " " + descision;
	ofstream add_log_data;
	add_log_data.open("Logs.txt", ios_base::app);
	add_log_data << log_info;
}

void Data::add_user(string first_name, string last_name, string role) {
	SecureCard new_secure_card;
	Card new_card;
	string card_id;
	if (role == "Security") {
		card_id = new_secure_card.getSecureCardID();
	}
	else {
		card_id = new_card.getCardID();
	}
	

	ifstream user_file("Users.txt");
	string data_piece;
	vector<string> data_pieces;
	while (user_file >> data_piece) {
		data_pieces.push_back(data_piece);
	}

	for (string data : data_pieces) {
		
		if (data == card_id) {
			if (role == "Security") {
				card_id = new_secure_card.getSecureCardID();
			}
			else {
				card_id = new_card.getCardID();
			}
			
		}
	}
	string user_info = "\n"+card_id + " " + first_name + " " + last_name + " " + role;
	ofstream add_user_data;
	add_user_data.open("Users.txt", ios_base::app);
	add_user_data << user_info;
}

void Data::add_room(string room_id, string room_type, string room_state) {
	string room_info = "\n" + room_id + " " + room_type + " " + room_state;
	ofstream add_room_data;
	add_room_data.open("Rooms.txt", ios_base::app);
	add_room_data<<"\n" << room_info;
}

