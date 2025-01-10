#include "Card.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
string Card::generate_id() {
	string card_id;
	srand(time(0));
	int odd_numbers[5] = {1,3,5,7,9};
	int random;
	for (int i = 0; i < 5; i++) {
		
		random = rand() % 4 + 1;
		if (random == 9) {
			i - 1;
		}
		else {
			card_id += to_string(odd_numbers[random]);
		}
	}
	return card_id;
};




