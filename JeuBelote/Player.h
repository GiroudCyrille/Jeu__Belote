#ifndef Player_H
#define Player_H

#include "Card.h"
#include "Team.h"

class Player
{
protected:
	vector<Card> playerCards;
	Team* playerTeam;

public:
	Player(Team* team);
	~Player() {};

	void setCards(vector<Card>& card, int iP);
	void playCard(int card, vector<Card>& cards);
	void setAtout(int atout, bool active);
	void showCards();
	virtual void play(vector<Card>& cards) {};

	vector<Card> getCards() { return playerCards; }
	Team* getTeam() {
		return playerTeam;
	}
};

#endif // !Player_H