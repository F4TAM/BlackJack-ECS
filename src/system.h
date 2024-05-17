#pragma once

#include <vector>
#include <string>
#include "components.h"
#include "entities.h"
#include <typeindex>
#include <unordered_map>
#include <random>
#include <iostream>

/**
 * @class BlackjackSystem
 * @brief System for handling the core mechanics of a blackjack game.
 */
    class BlackjackSystem {
    public:
        /**
         * @brief Calculates the score of hands, checks for blackjack, and updates scores accordingly.
         * @param player Pointer to the player entity.
         * @param dealer Pointer to the dealer entity.
         */
        void calculateScore(Entity* player, Entity* dealer);

        /**
         * @brief Restarts the game by resetting the player, dealer, and deck entities.
         * @param player Pointer to the player entity.
         * @param dealer Pointer to the dealer entity.
         * @param deck Pointer to the deck entity.
         */
        void restart(Entity* player, Entity* dealer, Entity* deck);
};

/**
 * @class DeckSystem
 * @brief System for managing the deck of cards in a blackjack game.
 */
class DeckSystem {
public:
    /**
     * @brief Initializes the deck of cards.
     * @param deck Pointer to the deck entity.
     */
    void initDeck(Entity* deck);

    /**
     * @brief Deals a specified number of cards to the given entity (player or dealer).
     * @param deck Pointer to the deck entity.
     * @param entity Pointer to the entity receiving the cards.
     * @param amount The number of cards to deal (default is 1).
     */
    void dealCard(Entity* deck, Entity* entity, int amount = 1);

    /**
     * @brief Shuffles the deck of cards.
     * @param deck Pointer to the deck entity.
     */
    void shuffleDeck(Entity* deck);
};

/**
 * @class UISystem
 * @brief System for handling the user interface in a blackjack game.
 */
class UISystem {
public:
    /**
     * @brief Takes input from the player for hitting or standing.
     * @param entity Pointer to the player entity.
     */
    void takeInput(Entity* entity);

    /**
     * @brief Displays the cards of the player or dealer.
     * @param entity Pointer to the entity whose cards are being displayed.
     */
    void displayCards(Entity* entity);

    /**
     * @brief Displays the scores of the player or dealer.
     * @param entity Pointer to the entity whose score is being displayed.
     */
    void displayScores(Entity* entity);

    /**
     * @brief Displays the winner of the game.
     * @param player Pointer to the player entity.
     * @param dealer Pointer to the dealer entity.
     */
    void displayWinner(Entity* player, Entity* dealer);

    /**
     * @brief Clears the display.
     */
    void displayClear();

    /**
     * @brief Displays text on the screen.
     * @param text The text to be displayed.
     */
    void displayText(std::string text);
};