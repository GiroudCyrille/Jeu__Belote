#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Team
{
private:
	vector<Card> winCards;
	int additionalPoints;

public:
	~Team() {};

	void addCards(vector<Card> cards);
	void clear();
	int getPoints();
	int setAdditionalPoints(int amount) { return additionalPoints += amount; }
};

