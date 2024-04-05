#include "system.h"
#include <iostream>
#include <string>

int main()
{
    // Entities setup
    Entity player("player"); // Player
    player.addComponent(new HandComponent{});
    player.addComponent(new ScoreComponent{ 0 });
    player.addComponent(new InputComponent{ "" });
    player.addComponent(new NameComponent{ "Player" });
    player.addComponent(new StandComponent{ false });

    Entity dealer("dealer"); // Dealer
    dealer.addComponent(new HandComponent{});
    dealer.addComponent(new ScoreComponent{ 0 });
    dealer.addComponent(new InputComponent{ "" });
    dealer.addComponent(new NameComponent{ "Dealer" });
    dealer.addComponent(new StandComponent{ false });

    Entity deck("deck"); // Deck of cards
    deck.addComponent(new DeckComponent());

    Entity UI("UI"); // User Interface
    UI.addComponent(new UIComponent{ "" });

    // System setup
    DeckSystem deckSystem;
    UISystem ui;
    BlackjackSystem blackjackSystem;

    auto input = player.getComponent<InputComponent>();
    bool runtime = true;
    bool gameRunning = true;

    while (runtime)
    {
        // Initialize deck
        deckSystem.initDeck(&deck);
        deckSystem.shuffleDeck(&deck);
        // Deal cards
        deckSystem.dealCard(&deck, &player, 2);
        deckSystem.dealCard(&deck, &dealer, 2);

        while (gameRunning)
        {
            // UI display
            ui.displayClear();
            ui.displayCards(&dealer);
            ui.displayText("");
            ui.displayCards(&player);
            ui.displayText("");
            // Calculate and display scores
            blackjackSystem.calculateScore(&player, &dealer);
            ui.displayScores(&player);
            ui.displayText("");

            // Player's turn
            if (player.getComponent<StandComponent>()->stand == false)
            {
                ui.displayText("Player's Turn\n");
                ui.displayText("Hit Or Stand\n 1. Hit \n 2. Stand");
                ui.takeInput(&player);
            }

            // Player chooses to hit
            if (player.getComponent<InputComponent>()->input == "1")
            {
                deckSystem.dealCard(&deck, &player, 1);
                blackjackSystem.calculateScore(&player, &dealer);
            }
            // Player chooses to stand
            else if (player.getComponent<InputComponent>()->input == "2")
            {
                ui.displayText("Dealer's Turn\n");
                player.getComponent<StandComponent>()->stand = true;
            }

            {
                ui.displayText("Invalid Input\n");
            }

            // Dealer's turn
            // Dealer hits if their score is less than 17 and player has stood
            if (dealer.getComponent<ScoreComponent>()->score < 17 && player.getComponent<StandComponent>()->stand == true)
            {
                deckSystem.dealCard(&deck, &dealer, 1);
                blackjackSystem.calculateScore(&player, &dealer);
            }
            else
            {
                dealer.getComponent<StandComponent>()->stand = true;
            }

            // End game conditions
            if (player.getComponent<StandComponent>()->stand == true && dealer.getComponent<StandComponent>()->stand == true)
            {
                gameRunning = false;
            }
            else if (player.getComponent<ScoreComponent>()->score > 21)
            {
				gameRunning = false;
			}

            // Display winner and clear UI
            ui.displayClear();
            ui.displayWinner(&player, &dealer);
        }

        // Ask if the player wants to play again
        ui.displayText("Play Again? \n 1. Yes \n 2. No");
        ui.takeInput(&player);

        if (player.getComponent<InputComponent>()->input == "2")
        {
            runtime = false;
        }
        else
        {
            // Reset game state for a new round
            gameRunning = true;
            blackjackSystem.restart(&player, &dealer, &deck);
        }
    }
    return 1;
}
