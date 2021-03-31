// JeuBelote.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "Card.h"
#include "Team.h"
#include "Player.h"
#include <time.h>

using namespace std;

void loadCards(vector<Card>& cards, Symbol symbol)
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

void loadAllCards(vector<Card>& cards)
{
    loadCards(cards, Symbol::Carreau);
    loadCards(cards, Symbol::Coeur);
    loadCards(cards, Symbol::Pique);
    loadCards(cards, Symbol::Trefle);
}

int determinsWinner(vector<Card>& playCards, Player players[], bool last)
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

    players[winCard.getIndexPlayer()].getTeam()->addCards(playCards);
    cout << "Le joueur " << winCard.getIndexPlayer() << " a gagner" << endl;
    playCards.clear();

    if (last) {
        players[winCard.getIndexPlayer()].getTeam()->setAdditionalPoints(10);
        cout << "L'equipe gagnante remporte 10 points supplémentaires.";
    }

    return winCard.getIndexPlayer();
}

int main()
{
    srand(time(NULL));
    int atout, actualPlayer = 0;
    bool play = true;
    Team firstTeam;
    Team secondTeam;
    vector<Card> cards;
    vector<Card> playCards;
    Player players[4]{ Player(&firstTeam, false), Player(&secondTeam, true), Player(&firstTeam, true), Player(&secondTeam, true) };
    loadAllCards(cards);

    while (play)
    {
        cout << "Le jeu de belote :" << endl;

        for (int i = 0; i < size(cards); i++)
            cout << cards[i].toString(i + 1) << endl;

        cout << "On distribue le jeu de belottes.." << endl;
        for (int i = 0; i < size(players); i++)
            players[i].setCards(cards, i);

        for (int i = 0; i < 8; i++)
        {
            if (actualPlayer == 0) {
                players[0].showCards();
                cout << "Saisir l'atout : " << endl << "- 0:Carreau" << endl << "- 1:Trefle" << endl << "- 2:Pique" << endl << "- 3:Coeur" << endl;
                cin >> atout;
            }
            else
                atout = rand() % 4 + 0;

            for (int i = 0; i < size(players); i++)
                players[i].setAtout(atout, true);

            players[actualPlayer].play(playCards);

            for (int i = 0; i < size(players); i++)
            {
                if (i != actualPlayer)
                    players[i].play(playCards);
            }

            cout << "Les cartes sur la table sont  :" << endl;

            for (int i = 0; i < size(playCards); i++)
                cout << playCards[i].toString(i) << endl;

            cout << "Fin du pli numero " << i + 1 << endl;
            actualPlayer = determinsWinner(playCards, players, i == 8);

            for (int i = 0; i < size(players); i++)
                players[i].setAtout(atout, false);
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
        loadAllCards(cards);
        firstTeam.clear();
        secondTeam.clear();
    }
}