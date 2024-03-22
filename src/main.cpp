#include "system.h"
#include <iostream>
#include <string>


int main()
{
    Entity player("player"); // Player
    player.addComponent(new HandComponent{});
    player.addComponent(new ScoreComponent{0});
    player.addComponent(new InputComponent{""});
    player.addComponent(new NameComponent{"Player"});

    Entity dealer("dealer"); // Dealer
    dealer.addComponent(new HandComponent{});
    dealer.addComponent(new ScoreComponent{0});
    dealer.addComponent(new InputComponent{""});
    dealer.addComponent(new NameComponent{"Dealer"});

    Entity deck("deck"); // Deck of cards
    deck.addComponent(new DeckComponent());

    Entity UI("UI"); // User Interface
    UI.addComponent(new UIComponent{""});

    DeckSystem deckSystem;
    UISystem ui;
    ScoreSystem scoreSystem;
    BlackjackSystem blackjackSystem;

    
    auto input = player.getComponent<InputComponent>();
    bool runtime = true;
    bool gameRunning = true;
    while (runtime) 
    {
        //initialize deck
        deckSystem.initDeck(&deck);
        deckSystem.shuffleDeck(&deck);
        //deal cards
        deckSystem.dealCard(&deck, &player, 2);
        deckSystem.dealCard(&deck, &dealer, 2);


        while (gameRunning)
        {
            ui.displayClear();
            ui.displayCards(&dealer);
            ui.displayText("\n");
            ui.displayCards(&player);
            blackjackSystem.calculateScore(&player, &dealer);
            ui.displayScores(&player);
            ui.displayScores(&dealer);
            ui.displayText("Player's Turn\n");
            ui.displayText("Hit Or Stand\n 1. Hit \n 2. Stand");
            ui.takeInput(&player);
            blackjackSystem.dealerHitorStand(&dealer, &deck);
            
            

        }
    }




}