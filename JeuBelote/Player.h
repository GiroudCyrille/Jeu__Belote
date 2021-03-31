#ifndef Player_H
#define Player_H

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Team.h"

class Player
{
private:
	vector<Card> playerCards;
	Team* playerTeam;
	bool isAI;

public:
	Player(Team* team, bool isAI);
	Player() {};
	~Player() {};

	void setCards(vector<Card>& card, int iP);
	void playCard(int card, vector<Card>& cards);
	void setAtout(int atout, bool active);
	void showCards();
	void play(vector<Card>& cards);

	vector<Card> getCards() { return playerCards; }
	Team* getTeam() {
		return playerTeam;
	}
};

#endif // !Player_H