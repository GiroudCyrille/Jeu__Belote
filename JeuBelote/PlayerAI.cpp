#include "PlayerAI.h"

PlayerAI::PlayerAI(Team* team) : Player(team)
{
}

void PlayerAI::play(vector<Card>& cards)
{
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