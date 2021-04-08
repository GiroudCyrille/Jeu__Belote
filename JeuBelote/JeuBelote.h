#pragma once
#include "Card.h"
#include "Team.h"
#include "Player.h"
#include <time.h>

class JeuBelote
{
private:
	vector<Card> cards;
	vector<Card> playCards;
	vector<Player*> players;
	Team firstTeam;
	Team secondTeam;

public:
	~JeuBelote() {};
	void play();
	void loadAllCards();
	void loadPlayers();
	void loadCards(Symbol symbol);
	int determinsWinner(bool lastRound);
};