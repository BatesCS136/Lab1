#ifndef COIN_H
#define COIN_H

struct Coin {
	int denom;
	long count;
	const char *single;
	const char *multiple;
};

#endif