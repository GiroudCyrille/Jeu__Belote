#include "PlayerHuman.h"

PlayerHuman::PlayerHuman(Team* team) : Player(team)
{
}

void PlayerHuman::play(vector<Card>& cards)
{
	int choice = 0;

	showCards();
	cout << "Les cartes sur la table sont  :" << endl;

	for (int i = 0; i < size(cards); i++)
		cout << cards[i].toString(i) << endl;

	cout << "Choisir carte : " << endl;
	cin >> choice;

	playCard(choice - 1, cards);
}