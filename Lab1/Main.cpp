/*
// Author: Garrett Bates
// Created: Sept 29, 2014
// Last Modified: Sept 30, 2014
// Lab 1: Show me the MONEY!
// File name: Main.cpp
//
// OVERVIEW
// 
// This program displays the amount of quarters, dimes,
// nickels, and pennies that would be returned given an
// amount of change.
//
// INPUT:
//
// This program takes user input in the form of integer
// numbers representing the amount of cents. 
// 
// OUTPUT:
//
// The amount of quarters, dimes, nickels, and pennies 
// returned as change, provided that the count of each
// is greater than zero.
*/

#include <iostream>
#include "Coin.h"
#include <Windows.h>

using namespace std;

// This function initializes each Coin with the appropriate values.
void initCoins (Coin iCoins []);

// This function provides the prompt to the user to enter the amount
// of change.
void Menu(Coin iCoins[]);

// This function computes the quantity of Coins returned to the user.
void Change(long &iAmount, Coin &iCoin);

// This function outputs the quantity of Coins returned to the user.
const void Print(Coin &iCoin);


// Declaring a constant array size of 4.
const short ARRAY_SIZE = 4;

/*
//	PURPOSE: Declare and initialize the array of four Coin structures.
//	
//	ENTRY: At execution of the program.
//	
//	EXIT: After the user enters a value of -1 in the Menu function or
//	terminates the program manually.
*/

int main() {	
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	Coin coins[4];
	initCoins(coins);
	Menu(coins);
	return 0;
}

/*
//	PURPOSE: Each of the Coins is given a denomination, initial quantity of zero,
//	and a label that is used depending on whether the quantity of that
//	Coin is one or greater. e.g. If the amount of change returned involves
//	only one quarter, the label "quarter" will be used, and not "quarters."
//	
//	ENTRY: When an array of Coin is passed from main()
//	
//	EXIT: After the default values for each Coin are assigned.
*/

void initCoins(Coin iCoins []) {
	iCoins[0] = Coin{ 25, 0, "quarter", "quarters" };
	iCoins[1] = Coin{ 10, 0, "dime", "dimes" };
	iCoins[2] = Coin{ 5, 0, "nickel", "nickels" };
	iCoins[3] = Coin{ 1, 0, "penny", "pennies" };
}

/*
//	PURPOSE: Here  the user is asked to enter the amount of change
//	to be returned. The integer value will be stored in 'amount.'
//	A value of -1 will cause the program to terminate.
//	
//	If the amount is greater than or equal to one, then the
//	amount and the array of Coins will be passed to the 
//	Change function where the appropriate quantity of coins
//	of each denomination will be determined and passed to
//	the Print function for possible display.
//	
//	ENTRY: From main() after the Coin array has been filled.
//	
//	EXIT: When the user enters a value of -1 to terminate the
//	program.
*/

void Menu(Coin iCoins[]) {
	long amount = 0; // The amount of change entered by the user.

	while (true) {
		cout << "Enter money amount (e.g. 145 = $1.45, -1 to quit): ";
		cin >> amount;

		if (amount == -1) {
			cout << "\n\nGood day to you!" << endl;
			exit(0);
		}

		if (amount >= 1) {
			cout << "\nYour change:" << endl;

			for (int i = 0; i < ARRAY_SIZE; ++i) {
				Change(amount, iCoins[i]);
				Print(iCoins[i]);
			}

			cout << endl << endl;
		}
	}
}

/*
//	PURPOSE: Coin quantities are determined through simple division.
//	To find the remaining change, we subtract the amount
//	by the value of the quantity and denomination of that
//	particular Coin.
//	
//	ENTRY: From the FOR LOOP in Menu(). Coin structs are passed into this
//	function one at a time.
//	
//	EXIT: After the quantity of each Coin is determined and the remaining
//	amount of change is determined.
*/

void Change(long &iAmount, Coin &iCoin) {
	iCoin.count = iAmount / iCoin.denom;
	iAmount -= iCoin.count * iCoin.denom;
}

/*
//	PURPOSE: Here the label and quantity of each Coin passed is
//	printed out, provided that its quantity is greater
//	than zero. If the quantity is greater than one, then
//	the plural label is chosen, otherwise the singular
//	form is chosen.
//	
//	ENTRY: From the FOR LOOP in Menu(). Each Coin is passed one
//	at a time. 
//	
//	EXIT: After the quantity of coins is checked. If the quantity is
//	one or greater, then the proper label and amount will be displayed.
*/

const void Print(Coin &iCoin) {
	if (iCoin.count > 1) {
		cout << iCoin.multiple << ": " << iCoin.count << endl;
	}
	else if (iCoin.count == 1) {
		cout << iCoin.single << ": " << iCoin.count << endl;
	}
}
