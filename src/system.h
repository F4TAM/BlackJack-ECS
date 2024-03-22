#pragma once   
#include <vector>
#include <string>
#include "components.h"
#include "entities.h"
#include <typeindex>
#include <unordered_map>
#include <random>
#include <iostream>



class BlackjackSystem
{
    public:
    // calculates the score of hands, checks for blackjack and 
    void calculateScore(Entity* player, Entity* dealer);
    void hitOrStand(Entity* player, Entity* dealer);
};

class DeckSystem
{
    public:
    // Deals card to the player and dealer
    void initDeck(Entity* deck);
    void dealCard(Entity* deck, Entity* entity, int amount = 1);
    void shuffleDeck(Entity* deck);
};

class ScoreSystem
{
    // updates the score of the player and dealer, and checks for blackjack
    // and special values such as aces being counted as 1 or 11
};

class UISystem
{

    public:
    void takeInput(Entity* entity);
	// displays the cards and scores of the player and dealer
	void displayCards(Entity* entity);
	void displayScores(Entity*  entity);
    void displayWinner(Entity* Player, Entity* dealer);
    void displayClear();
    void displayText(std::string text);
};