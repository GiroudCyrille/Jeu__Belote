#ifndef Card_H
#define Card_H
#include <iostream>

using namespace std;

enum Symbol { Carreau, Trefle, Pique, Coeur};
enum Cards { As, Roi, Dame, Valet, Dix, Neuf, Huit, Sept};

static const char* enum_symbol_str[] =
	{ "Carreau", "Trefle", "Pique", "Coeur" };
static const char* enum_cards_str[] =
	{ "As", "Roi", "Dame", "Valet", "Dix", "Neuf", "Huit", "Sept" };

class Card
{
private:
	int value, atoutValue, indexPlayer;
	bool atout;
	Symbol symbol;
	Cards card;

public:
	Card() { atout = false; };
	Card(int value, int atoutValue, Symbol symbol, Cards card);
	~Card() {};

	string getStringForSymbol() { return enum_symbol_str[symbol]; }
	string getStringForCards() { return enum_cards_str[card]; }
	string toString(int i);
	Symbol getSymbol() { return symbol; }
	int getValue() { return atout ? atoutValue : value; }
	int getIndexPlayer() { return indexPlayer; }
	bool isAtout() { return atout; }

	void setAtout(bool value)
	{
		atout = value;
	}

	void setIndexPlayer(int iP)
	{
		indexPlayer = iP;
	}
};
#endif Card_H

