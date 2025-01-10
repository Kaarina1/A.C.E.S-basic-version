#include "SecureCard.h"

	string SecureCard::secure_card_id() {
		string card_id = Card::generate_id();

		card_id = "999" + card_id;

		return card_id;
	}
