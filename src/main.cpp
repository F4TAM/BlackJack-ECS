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

    
   

    bool gameRunning = true;

    while (gameRunning)
    {
        ui.displayClear();
        deckSystem.initDeck(&deck);
        deckSystem.shuffleDeck(&deck);
        deckSystem.dealCard(&deck, &player);
        ui.displayCards(&player);
        ui.takeInput(&player);
        blackjackSystem.calculateScore(&player, &dealer);

    }



}