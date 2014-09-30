/*
// Author: Garrett Bates
// Date: Sept 29, 2014
// Lab 1: Show me the MONEY!
*/

#include <iostream>
#include "Coin.h"

using namespace std;

/*
// Function prototypes
*/

void initCoins (Coin iCoins []);
void Menu(Coin iCoins[]);
void Change(long &iAmount, Coin &iCoin);
const void Print(Coin &iCoin);

int main() {

	/*
	// Declare and initialize the array of four Coin structures
	*/

	Coin coins[4];
	initCoins(coins);

	Menu(coins);

	return 0;
}

void initCoins(Coin iCoins []) {

	/*
	// Each of the Coins is given a denomination, initial quantity of zero,
	// and a label that is used depending on whether the quantity of that
	// Coin is one or greater. e.g. If the amount of change returned involves
	// only one quarter, the label "quarter" will be used, and not "quarters."
	*/

	iCoins[0] = Coin{ 25, 0, "quarter", "quarters" };
	iCoins[1] = Coin{ 10, 0, "dime", "dimes" };
	iCoins[2] = Coin{ 5, 0, "nickel", "nickels" };
	iCoins[3] = Coin{ 1, 0, "penny", "pennies" };
}

void Menu(Coin iCoins[]) {

	/* 
	// Here  the user is asked to enter the amount of change
	// to be returned. The integer value will be stored in 'amount.'
	// A value of -1 will cause the program to terminate.
	*/

	long amount = 0;

	while (true) {
		cout << "Enter money amount (e.g. 145 = $1.45, -1 to quit): ";
		cin >> amount;

		if (amount == -1) {
			cout << "\n\nGood day to you!" << endl;
			exit;
		}

		/*
		// If the amount is greater than or equal to one, then the
		// amount and the array of Coins will be passed to the 
		// Change function where the appropriate quantity of coins
		// of each denomination will be determined and passed to
		// the Print function for possible display.
		*/

		if (amount >= 1) {

			cout << "\n\nYour change:" << endl;

			for (int i = 0; i < 4; ++i) {
				Change(amount, iCoins[i]);
				Print(iCoins[i]);
			}

			cout << endl;
		}
	}
}

void Change(long &iAmount, Coin &iCoin) {

	/*
	// Coin quantities are determined through simple division.
	// To find the remaining change, we subtract the amount
	// by the value of the quantity and denomination of that
	// particular Coin.
	*/

	iCoin.count = iAmount / iCoin.denom;
	iAmount -= iCoin.count * iCoin.denom;
}

const void Print(Coin &iCoin) {

	/*
	// Here the label and quantity of each Coin passed is
	// printed out, provided that its quantity is greater
	// than zero. If the quantity is greater than one, then
	// the plural label is chosen, otherwise the singular
	// form is chosen.
	*/

	if (iCoin.count > 1) {
		cout << iCoin.multiple << ": " << iCoin.count << endl;
	}
	else if (iCoin.count == 1) {
		cout << iCoin.single << ": " << iCoin.count << endl;
	}
}