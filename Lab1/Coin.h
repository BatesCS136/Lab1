#ifndef COIN_H
#define COIN_H

/*
// Each Coin structure is given a denomination, quantity,
// and two labels for use when the quantity is greater
// than one.
*/

struct Coin {
	int denom;
	long count;
	const char *single;
	const char *multiple;
};

#endif