#pragma once

#include "Player.h"

class PlayerAI : public Player
{
public:
	PlayerAI(Team* team);
	virtual void play(vector<Card>& cards);
};

