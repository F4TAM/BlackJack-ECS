
#include <iostream>
#include <string>


int main()
{
    Entity player;
    Entity dealer;
    player.addComponent(new InputComponent());
    dealer.addComponent(new InputComponent());
    player.addComponent(new ScoreComponent());
    dealer.addComponent(new ScoreComponent());
    player.addComponent(new HandComponent());
    dealer.addComponent(new HandComponent());

    bool gameRunning = true;

    std::string clearConsole = "\033[2J\033[1;1H";
    std::string startUI = "Welcome to Blackjack! Press 's' to start the game or 'q' to quit: \n";

    while (gameRunning)
    {
        std::cout << clearConsole;
        std::cout << startUI;

    }



}