#include "Player.h"
#include <cstdlib>

Player::Player(Team* team)
{
	playerTeam = team;
}

void Player::setCards(vector<Card>& cards, int indexPlayer)
{
	for (int i = 0; i < 8; i++) {
		int randNumber = rand() % size(cards) + 0;
		cards[randNumber].setIndexPlayer(indexPlayer);
		playerCards.push_back(cards[randNumber]);
		cards.erase(cards.begin() + randNumber);
	}
}

void Player::setAtout(int atout, bool active)
{
	for (int i = 0; i < size(playerCards); i++)
	{
		if (playerCards[i].getSymbol() == atout)
			playerCards[i].setAtout(active);
	}
}

void Player::showCards()
{
	cout << "Votre main" << endl;
	for (int i = 0; i < size(playerCards); i++)
		cout << playerCards[i].toString(i) << endl;
}

void Player::playCard(int card, vector<Card>& cards)
{
	cards.push_back(playerCards[card]);
	playerCards.erase(playerCards.begin() + card);
}