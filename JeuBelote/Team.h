#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Team
{
private:
	vector<Card> winCards;
	int additionalPoints;

public:
	Team() {};
	~Team() {};

	void addCards(vector<Card> cards);
	void clear();
	int getPoints();
	int setAdditionalPoints(int amount) { return additionalPoints += amount; }
};

