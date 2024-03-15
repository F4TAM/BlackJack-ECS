#pragma once

#include "components.h"
#include "entities.h"

class InputSystem
{
    // taking input from user whether to hit or stand
    void takeInput();

};

class BlackjackSystem
{
    // calculates the score of hands, checks for blackjack and 
    // and determine who's the winner ot loser
};

class CardSystem
{
    // Deals card to the player and dealer
};

class ScoreSystem
{
    // updates the score of the player and dealer, and checks for blackjack
    // and special values such as aces being counted as 1 or 11
};