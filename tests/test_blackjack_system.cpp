#include <iostream>
#include <cassert>
#include "system.h"

void testCalculateScore() {
    // Create player and dealer entities
    Entity player("Player");
    Entity dealer("Dealer");

    // Create and add necessary components to the player
    auto playerHand = new HandComponent();
    auto playerScore = new ScoreComponent();
    player.addComponent(playerHand);
    player.addComponent(playerScore);

    // Create and add necessary components to the dealer
    auto dealerHand = new HandComponent();
    auto dealerScore = new ScoreComponent();
    dealer.addComponent(dealerHand);
    dealer.addComponent(dealerScore);

    // Add cards to the player's hand
    playerHand->cards.push_back({ "Hearts", "10" }); // 10 of Hearts
    playerHand->cards.push_back({ "Diamonds", "Ace" }); // Ace of Diamonds

    // Add cards to the dealer's hand
    dealerHand->cards.push_back({ "Clubs", "King" }); // King of Clubs
    dealerHand->cards.push_back({ "Spades", "5" }); // 5 of Spades

    // Create a BlackjackSystem object and calculate scores
    BlackjackSystem blackjackSystem;
    blackjackSystem.calculateScore(&player, &dealer);

    // Check the scores
    assert(playerScore->score == 21); // 10 + 11 = 21
    assert(dealerScore->score == 15); // 10 + 5 = 15

    // Output the results
    std::cout << "Player's Score: " << playerScore->score << "\n";
    std::cout << "Dealer's Score: " << dealerScore->score << "\n";
    std::cout << "Test Passed!\n";
}

int main() {
    testCalculateScore();
    return 0;
}
