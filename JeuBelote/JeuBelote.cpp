#include "JeuBelote.h"
#include "PlayerAI.h"
#include "PlayerHuman.h"

void JeuBelote::loadCards(Symbol symbol)
{
    cards.push_back(Card(11, 11, symbol, Cards::As));
    cards.push_back(Card(10, 10, symbol, Cards::Dix));
    cards.push_back(Card(4, 4, symbol, Cards::Roi));
    cards.push_back(Card(3, 3, symbol, Cards::Dame));
    cards.push_back(Card(2, 20, symbol, Cards::Valet));
    cards.push_back(Card(0, 14, symbol, Cards::Neuf));
    cards.push_back(Card(0, 0, symbol, Cards::Huit));
    cards.push_back(Card(0, 0, symbol, Cards::Sept));
}

void JeuBelote::loadAllCards()
{
    loadCards(Symbol::Carreau);
    loadCards(Symbol::Coeur);
    loadCards(Symbol::Pique);
    loadCards(Symbol::Trefle);
}

void JeuBelote::loadPlayers()
{
    players.push_back(new PlayerHuman(&firstTeam));
    players.push_back(new PlayerAI(&secondTeam));
    players.push_back(new PlayerAI(&firstTeam));
    players.push_back(new PlayerAI(&secondTeam));
}

int JeuBelote::determinsWinner(bool last)
{
    Card winCard;

    for (Card card : playCards)
    {
        if (card.isAtout() && card.getValue() > winCard.getValue())
            winCard = card;
    }

    if (!winCard.isAtout())
    {
        for (Card card : playCards)
        {
            if (card.getSymbol() == playCards[0].getSymbol() && card.getValue() > winCard.getValue())
                winCard = card;
        }
    }

    players[winCard.getIndexPlayer()]->getTeam()->addCards(playCards);
    cout << "Le joueur " << winCard.getIndexPlayer() << " a gagner" << endl;
    playCards.clear();

    if (last) {
        players[winCard.getIndexPlayer()]->getTeam()->setAdditionalPoints(10);
        cout << "L'equipe gagnante remporte 10 points supplémentaires.";
    }

    return winCard.getIndexPlayer();
}

void JeuBelote::play()
{
    srand(time(NULL));
    int atout, actualPlayer = 0;
    bool play = true;
    loadAllCards();
    loadPlayers();

    while (play)
    {
        cout << "Le jeu de belote :" << endl;

        for (int i = 0; i < size(cards); i++)
            cout << cards[i].toString(i + 1) << endl;

        cout << "On distribue le jeu de belottes.." << endl;
        for (int i = 0; i < size(players); i++)
            players[i]->setCards(cards, i);

        for (int i = 0; i < 8; i++)
        {
            if (actualPlayer == 0) {
                players[0]->showCards();
                cout << "Saisir l'atout : " << endl << "- 0:Carreau" << endl << "- 1:Trefle" << endl << "- 2:Pique" << endl << "- 3:Coeur" << endl;
                cin >> atout;
            }
            else
                atout = rand() % 4 + 0;

            for (int i = 0; i < size(players); i++)
                players[i]->setAtout(atout, true);

            players[actualPlayer]->play(playCards);

            for (int i = 0; i < size(players); i++)
            {
                if (i != actualPlayer)
                    players[i]->play(playCards);
            }

            cout << "Les cartes sur la table sont  :" << endl;

            for (int i = 0; i < size(playCards); i++)
                cout << playCards[i].toString(i) << endl;

            cout << "Fin du pli numero " << i + 1 << endl;
            actualPlayer = determinsWinner(i == 8);

            for (int i = 0; i < size(players); i++)
                players[i]->setAtout(atout, false);
        }

        if (firstTeam.getPoints() > secondTeam.getPoints()) {
            cout << "La premiere equipe a gagner avec " << firstTeam.getPoints() << " points" << endl;
            cout << "La deuxieme equipe a marquer " << secondTeam.getPoints() << " points" << endl;
        }
        else {
            cout << "La seconde equipe a gagner avec " << secondTeam.getPoints() << " points" << endl;
            cout << "La premiere equipe a marquer " << firstTeam.getPoints() << " points" << endl;
        }

        char continu;
        cout << "Voulez vous refaire une partie ? (y ou n)" << endl;
        cin >> continu;

        if (continu == 'n')
            play = false;

        system("CLS");
        loadAllCards();
        firstTeam.clear();
        secondTeam.clear();
    }
}