#pragma once

#include "Player.h"

class PlayerHuman : public Player
{
public:
	PlayerHuman(Team* team);

	virtual void play(vector<Card>& cards);
};