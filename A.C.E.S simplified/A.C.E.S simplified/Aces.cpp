#include "Aces.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Defining Functions
#include "Data.h"
#include "CardReaderFacade.h"

void simulation_menu();
void simulation_inputs();
void manage_users();

void add_user();
void add_room();


void manage_rooms();
void view_logs();
void main_menu();

int main(){
	main_menu();
	return 0;
}

int option = 0;

void main_menu() {
	//https://cboard.cprogramming.com/cplusplus-programming/162291-simple-menu-program.html
	// https://www.geeksforgeeks.org/menu-driven-c-program-for-a-simple-calculator/
	do {
		system("CLS");
		cout << "Main Menu";
		cout << "\nChoose one of the following options: ";
		cout << "\nOption 1: Manage Users";
		cout << "\nOption 2: Manage Rooms";
		cout << "\nOption 3: View Logs";
		cout << "\nOption 4: Start Simulation\n";
		cin >> option;
		//https://cplusplus.com/forum/beginner/51815/#google_vignette
		if (!cin) cin.clear();  
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	} while (option < 1 || option > 4);


	switch (option) {
	case 1:
		manage_users();
		break;
	case 2:
		manage_rooms();
		break;
	case 3:
		view_logs();
		break;
	case 4:
		simulation_menu();
		break;
	}
}


void manage_users() {
	
	do {
		system("CLS");
		cout << "Manage Users";
		cout << "\nChoose one of the following options: ";
		cout << "\nOption 1: View Users";
		cout << "\nOption 2: Add Users";
		cout << "\nOption 3: Edit Users";
		cout << "\nOption 4: Delete Users";
		cout << "\nOption 5: Return To Menu\n";
		cin >> option;
		//https://cplusplus.com/forum/beginner/51815/#google_vignette
		if (!cin) cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	} while (option < 1 || option > 5);


	switch (option) {
	case 1:
		do {
			
			system("CLS");
			Data data_users;
			cout << "View Users\n";
			cout << "***************************************\n";
			data_users.get_users();
			cout << "***************************************\n";
			cout << "\nOption 1: Return To Menu\n";
			cin >> option;
			//https://cplusplus.com/forum/beginner/51815/#google_vignette
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option != 1);
		main_menu();
		break;
	case 2:
		add_user();
		break;
	case 3:
		do {
			system("CLS");
			cout << "Edit Users\n";
			cout << "***************************************\n";
			cout << "\nThis is a furture update\n";
			cout << "***************************************\n";
			cout << "\nOption 1: Return To Menu\n";
			cin >> option;
			//https://cplusplus.com/forum/beginner/51815/#google_vignette
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option != 1);
		main_menu();
		break;
	case 4:
		do {
			system("CLS");
			cout << "Delete Users\n";
			cout << "***************************************\n";
			cout << "\nThis is a furture update\n";
			cout << "***************************************\n";
			cout << "\nOption 1: Return To Menu\n";
			cin >> option;
			//https://cplusplus.com/forum/beginner/51815/#google_vignette
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option != 1);
		main_menu();
		break;
	case 5:
		main_menu();
		break;
	}
}

void add_user() {
	string first_name;
	string last_name;
	string role;
		system("CLS");
		cout << "Add User";
		cout << "\n***************************************\n";
		cout << "\nFirst Name\n";
		cin >> first_name;
		if (first_name == "") {
			cout << "\nEnter First Name\n";
			cin >> first_name;
		}
		cout << "\nLast Name\n";
		cin >> last_name;
		cout << "\nRole\n";
		cin >> role;
		if (last_name == "") {
			cout << "\nEnter First Name\n";
			cin >> last_name;
		}

		if (role == "Lecturer" || role == "Student" || role == "Manager" || role == "Cleaner" || role == "Security" || role == "Guest" || role == "Emergency") {
			Data user_data;
			user_data.add_user(first_name, last_name, role);

		}
		else {
			cout << "\nEnter Valid Role\n";
			cin >> role;
		}
		do {
			cout << "***************************************\n";
			cout << "\nOption 1: Return To Menu\n";
			cin >> option;
			//https://cplusplus.com/forum/beginner/51815/#google_vignette
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option != 1);
		main_menu();
}

void manage_rooms() {

	do {
		system("CLS");
		cout << "Manage Rooms";
		cout << "\nChoose one of the following options: ";
		cout << "\nOption 1: View Rooms";
		cout << "\nOption 2: Add Rooms";
		cout << "\nOption 3: Edit Rooms";
		cout << "\nOption 4: Delete Rooms";
		cout << "\nOption 5: Change Room State";
		cout << "\nOption 6: Return To Menu\n";

		cin >> option;
		//https://cplusplus.com/forum/beginner/51815/#google_vignette
		if (!cin) cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	} while (option < 1 || option > 6);
	
	switch (option) {
	case 1:
		do {
			cout << "View Rooms\n";
			system("CLS");
			Data data_rooms;
			cout << "***************************************\n";
			data_rooms.get_rooms();
			cout << "***************************************\n";
			cout << "\nOption 1: Return To Menu\n";
			cin >> option;
			//https://cplusplus.com/forum/beginner/51815/#google_vignette
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option != 1);
		main_menu();
		cout << "Working";
		break;
	case 2:
		add_room();
		break;
	case 3:
		do {
			system("CLS");
			cout << "Edit Rooms\n";
			cout << "***************************************\n";
			cout << "\nThis is a furture update\n";
			cout << "***************************************\n";
			cout << "\nOption 1: Return To Menu\n";
			cin >> option;
			//https://cplusplus.com/forum/beginner/51815/#google_vignette
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option != 1);
		main_menu();
		break;
	case 4:
		do {
			system("CLS");
			cout << "Delete Rooms\n";
			cout << "***************************************\n";
			cout << "\nThis is a furture update\n";
			cout << "***************************************\n";
			cout << "\nOption 1: Return To Menu\n";
			cin >> option;
			//https://cplusplus.com/forum/beginner/51815/#google_vignette
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option != 1);
		main_menu();
		break;
	case 5:
		do {
			system("CLS");
			cout << "Edit Rooms\n";
			cout << "***************************************\n";
			cout << "\nThis is a furture update\n";
			cout << "***************************************\n";
			cout << "\nOption 1: Return To Menu\n";
			cin >> option;
			//https://cplusplus.com/forum/beginner/51815/#google_vignette
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option != 1);
		break;
	case 6:
		main_menu();
		break;
	}
}

void add_room() {
	string room_id;
	string room_type;
	string room_state;
	system("CLS");
	cout << "Add Room";
	cout << "\n***************************************\n";
	cout << "\nRoom ID\n";
	cin >> room_id;
	if (room_id == "") {
		cout << "Enter Room ID";
		cin >> room_id;
	}
	cout << "\nRoom Type\n";
	cin >> room_type;
	if (room_type == "" && room_type !="Lecture" && room_type != "Secure" && room_type != "Staff" && room_type != "Teaching") {
		cout << "\nEnter Valid Room Type\n";
		cin >> room_type;
	}
	cout << "\nState\n";
	cin >> room_state;
	if (room_state == "" && room_state !="E" && room_state != "N") {
		cout << "\nEnter Valid Room State\n";
		cin >> room_state;
	}
	

	Data user_data;
	user_data.add_room(room_id, room_type, room_state);

	do {
		cout << "***************************************\n";
		cout << "\nOption 1: Return To Menu\n";
		cin >> option;
		//https://cplusplus.com/forum/beginner/51815/#google_vignette
		if (!cin) cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	} while (option != 1);
	main_menu();

}

void view_logs() {
	
	do {
		cout << "View Logs\n";
		system("CLS");
		Data data_log;
		cout << "***************************************\n";
		data_log.get_logs();
		cout << "\n***************************************\n";
		cout << "\nOption 1: Return To Menu\n";
		cin >> option;
		//https://cplusplus.com/forum/beginner/51815/#google_vignette
		if (!cin) cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	} while (option !=1);
		main_menu();
}

void simulation_menu() {
	do {
	system("CLS");
	cout << "Card Entry Simulation\n\n";
	cout << "***************************************\n";
	cout << "In the following simulation you will need to enter a Card ID and Room ID \n";
	cout << "These can either be authentic or invalid\n";
	cout << "\n***************************************\n";
	cout << "Option 1: Begin:\n";
	cout << "\nOption 2: Return To Menu\n";
	cin >> option;
	if (!cin) cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	} while (option < 1 || option > 2);

	if (option == 1) {
		simulation_inputs();
	}
	else {
		main_menu();
	}
}

void simulation_inputs() {
	int  card_number;
	string room_id;
	bool card_is_number=false;
	do {
		system("CLS");
		cout << "Card Entry Simulation\n\n";
		cout << "Enter Card ID:\n";
		cin >> card_number;
		if (!cin) cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	}while (card_number <1);
	string card_id = to_string(card_number);
	
	
	cout << "\nEnter Room ID:\n";
	cin >> room_id;
	string choice;
	do {
		cout << "\n________________________\n";
		cout << "Option 1: Simulate Swipe Card:\n";
		cout << "\nOption 2: Return To Menu\n";
		cin >> option;
		if (!cin) cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	} while (option < 1 || option > 2);
	
	if (option == 2) {
		main_menu();
	}
	else {
		system("CLS");
		CardReaderFacade swipe_card;
		bool door_unlocked = swipe_card.card_reader(card_id, room_id);
		if (door_unlocked) {
			cout << "\nDoor Unlocked";
			cout << "\n________________________\n";
		}
		else {
			cout << "\nUnauthorised Access\n";
			cout << "\n________________________\n";
		};

		do {
		
			cout << "\nOption 1: Restart Simulation\n";
			cout << "\nOption 2: Return to Main Menu\n";
			cin >> option;
			if (!cin) cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (option < 1 || option > 2);

		if (option == 1) {
			simulation_menu();
		}
		else {
			main_menu();
		}
	}
}

	