#include "Card.h"
#include <string>

Card::Card()
{
	atout = false;
}

Card::Card(int valu, int atVal, Symbol symbo, Cards car)
{
	value = valu;
	atoutValue = atVal;
	symbol = symbo;
	card = car;
	atout = false;
}

string Card::toString(int i)
{
	return to_string(i + 1) + ". " + (atout ? "*" : "") + "[" + getStringForCards() + " " + getStringForSymbol() + "] " + ( atout ? to_string(atoutValue) : to_string(value)) + "pts";
}