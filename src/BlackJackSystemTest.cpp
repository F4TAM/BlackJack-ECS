#include <gtest/gtest.h>
#include "components.h"
#include "entities.h"
#include "system.h"

TEST(BlackjackSystemTest, CalculateScoreTest) {
    Entity player("player");
    Entity dealer("dealer");

    // Add necessary components to player and dealer
    player.addComponent(new HandComponent{});
    player.addComponent(new ScoreComponent{});
    player.addComponent(new StandComponent{});
    player.addComponent(new InputComponent{});

    dealer.addComponent(new HandComponent{});
    dealer.addComponent(new ScoreComponent{});
    dealer.addComponent(new StandComponent{});
    dealer.addComponent(new InputComponent{});

    BlackjackSystem blackjackSystem;

    // Test 1: Simple hand values
    player.getComponent<HandComponent>()->cards = { {"Hearts", "Jack"}, {"Spades", "9"} };
    dealer.getComponent<HandComponent>()->cards = { {"Hearts", "7"}, {"Spades", "8"} };

    blackjackSystem.calculateScore(&player, &dealer);

    EXPECT_EQ(player.getComponent<ScoreComponent>()->score, 19);
    EXPECT_EQ(dealer.getComponent<ScoreComponent>()->score, 15);

    // Test 2: Handling Aces
    player.getComponent<HandComponent>()->cards = { {"Hearts", "Ace"}, {"Spades", "9"} };
    dealer.getComponent<HandComponent>()->cards = { {"Hearts", "King"}, {"Spades", "8"} };

    blackjackSystem.calculateScore(&player, &dealer);

    EXPECT_EQ(player.getComponent<ScoreComponent>()->score, 20);
    EXPECT_EQ(dealer.getComponent<ScoreComponent>()->score, 18);

    // Test 3: Different hand values
    player.getComponent<HandComponent>()->cards = { {"Hearts", "King"}, {"Spades", "5"}, {"Diamonds", "6"} };
    dealer.getComponent<HandComponent>()->cards = { {"Hearts", "3"}, {"Spades", "6"} };

    blackjackSystem.calculateScore(&player, &dealer);

    EXPECT_EQ(player.getComponent<ScoreComponent>()->score, 21);
    EXPECT_EQ(dealer.getComponent<ScoreComponent>()->score, 9);

    // Test 4: Another hand with Ace
    player.getComponent<HandComponent>()->cards = { {"Hearts", "Ace"}, {"Spades", "King"} };
    dealer.getComponent<HandComponent>()->cards = { {"Hearts", "9"}, {"Spades", "7"} };

    blackjackSystem.calculateScore(&player, &dealer);

    EXPECT_EQ(player.getComponent<ScoreComponent>()->score, 21);
    EXPECT_EQ(dealer.getComponent<ScoreComponent>()->score, 16);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
