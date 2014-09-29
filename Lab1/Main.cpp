#include <iostream>
#include "Coin.h"

using namespace std;

void initCoins (Coin iCoins []);
void menu();

int main() {

	Coin coins[4];

	menu();

	return 0;
}

void initCoins(Coin iCoins []) {
	iCoins[0] = { 25, 0, 'a', 'b' };
	iCoins[1] = { 10, 0, 'a', 'b' };
	iCoins[2] = { 5, 0, 'a', 'b' };
	iCoins[3] = { 1, 0, 'a', 'b' };
}

void menu() {
	int amount = 0;

	while (amount != -1) {
		cout << "Enter money amount: (e.g. 145 = $1.45, -1 to quit)" << endl;
		cin >> amount;

		if (amount >= 1) {

		}
	}
}