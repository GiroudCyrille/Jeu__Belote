#include "Player.h"
#include <cstdlib>

Player::Player(Team* team, bool isBot)
{
	playerTeam = team;
	isAI = isBot;
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

void Player::play(vector<Card>& cards)
{
	if (!isAI)
	{
		int choice = 0;

		showCards();

		cout << "Les cartes sur la table sont  :" << endl;

		for (int i = 0; i < size(cards); i++)
			cout << cards[i].toString(i) << endl;

		cout << "Choisir carte : " << endl;
		cin >> choice;

		playCard(choice, cards);
	}
	else {
		if (size(cards) == 0)
		{
			int randCard = rand() % size(playerCards) + 0;
			playCard(randCard, cards);
		}
		else {
			Card firstCard = cards[0];
			for (int i = 0; i < size(playerCards); i++)
			{
				if (playerCards[i].getSymbol() == firstCard.getSymbol())
				{
					playCard(i, cards);
					return;
				}
			}

			for (int i = 0; i < size(playerCards); i++)
			{
				if (playerCards[i].isAtout())
				{
					playCard(i, cards);
					return;
				}
			}

			int randCard = rand() % size(playerCards) + 0;
			playCard(randCard, cards);
		}
	}
}