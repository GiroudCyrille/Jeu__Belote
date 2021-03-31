#include "Team.h"

void Team::addCards(vector<Card> cards)
{
	for (Card card : cards)
		winCards.push_back(card);
}

void Team::clear()
{
	winCards.clear();
	additionalPoints = 0;
}

int Team::getPoints()
{
	int points = 0;
	for (Card card : winCards)
		points += card.getValue();

	return points + additionalPoints;
}