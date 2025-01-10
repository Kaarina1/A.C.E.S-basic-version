#include "CardReader.h"
#include "Data.h"

bool CardReader::check_access(string s_card_id, string door_id) {
	int card_id = stoi(s_card_id);
	bool verified = verify(card_id);
	if (verified) {
		bool authenticated = authenticate(s_card_id, door_id);
		if (authenticated) {
			bool authorised = authorise(s_card_id, door_id);
			Data log_details;
			log_details.log_access(s_card_id, door_id, authorised);

			return authorised;
		}
		else {
			return authenticated;
		}
	}
	else {
		return verified;
	}
}

bool CardReader::verify(int card_id) {

	bool odd = false;
	int temp = card_id;
	int remainder;
	//
	//Checks if all digits are odd
	while (temp > 0) {
		remainder = temp % 10;
		if (remainder % 2 != 0) {
			odd = true;
		}
		temp = temp / 10;
	}
	if (odd) {
		cout << "Verfied Card\n";
		return true;
	}
	else {
		cout << "Unverified Card ID\n";
	}
}

bool CardReader::authenticate(string card_id, string door_id) {

	Data check_id_data;
	bool authenticated_card = check_id_data.check_card(card_id);
	if (!authenticated_card) {

		return false;
	}
	bool valid_door = check_id_data.check_door(door_id);
	if (valid_door) {
		cout << "Authenticated Card\n";
	}
	else {
		cout << "Unauthenticated Card\n";
	}
	return valid_door;

}

bool CardReader::authorise(string card_id, string door_id) {
	Data check_authorisation;
	bool authorisation = check_authorisation.compare_ids(card_id, door_id);
	if (authorisation) {
		cout << "Authorised Card\n";
		return true;
	}
	else {
		cout << "Unauthorised Card\n";
		return false;
	}

}