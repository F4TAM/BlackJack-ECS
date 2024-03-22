#pragma once // Prevents multiple inclusions of this header file

#include <string> // Includes the string class for handling strings
#include <vector> // Includes the vector class for handling dynamic arrays
#include <memory> // Includes the memory class for handling smart pointers

// Struct representing a component for holding whether a player has stood
struct StandComponent
{
    bool stand; // Indicates if the player has chosen to stand
};

// Struct representing a component for holding a player's name
struct NameComponent
{
    std::string name; // Stores the name of the player
};

// Struct representing a component for holding player input
struct InputComponent
{
    std::string input; // Stores the input provided by the player
};

// Struct representing a component for holding information about a single card
struct CardComponent
{
    std::string suit; // Stores the suit of the card (e.g., "Hearts", "Diamonds", etc.)
    std::string rank; // Stores the rank of the card (e.g., "Ace", "2", "King", etc.)
};

// Struct representing a component for holding a hand of cards
struct HandComponent
{
    std::vector<CardComponent> cards; // Holds the cards in the hand as a vector of CardComponents
};

// Struct representing a component for holding a player's score
struct ScoreComponent
{
    int score; // Stores the score of the player
};

// Struct representing a component for holding UI output
struct UIComponent
{
    std::string output; // Stores output text for display on the user interface
};

// Struct representing a component for holding a deck of cards
struct DeckComponent
{
    std::vector<std::unique_ptr<CardComponent>> cards; // Holds the cards in the deck as unique pointers to CardComponents
};
