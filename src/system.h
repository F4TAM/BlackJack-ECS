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
    // Calculates the score of hands, checks for blackjack, and updates scores accordingly
    void calculateScore(Entity* player, Entity* dealer);
    void restart(Entity* player, Entity* dealer, Entity* deck);
};

class DeckSystem
{
public:
    // Initializes the deck of cards
    void initDeck(Entity* deck);

    // Deals specified number of cards to the given entity (player or dealer)
    void dealCard(Entity* deck, Entity* entity, int amount = 1);

    // Shuffles the deck of cards
    void shuffleDeck(Entity* deck);
};


class UISystem
{
public:
    // Takes input from the player for hitting or standing
    void takeInput(Entity* entity);

    // Displays the cards of the player or dealer
    void displayCards(Entity* entity);

    // Displays the scores of the player or dealer
    void displayScores(Entity* entity);

    // Displays the winner of the game
    void displayWinner(Entity* player, Entity* dealer);

    // Clears the display
    void displayClear();

    // Displays text on the screen
    void displayText(std::string text);
};
