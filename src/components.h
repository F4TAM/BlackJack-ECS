#pragma once // Prevents multiple inclusions of this header file

#include <string> // Includes the string class for handling strings
#include <vector> // Includes the vector class for handling dynamic arrays

// Struct representing a component for holding a name
struct NameComponent
{
    std::string name;
};

// Struct representing a component for holding information about a single card
struct CardComponent
{
    std::string suit, color; 
    int value; 
};

// Struct representing a component for holding a hand of cards
struct HandComponent
{
    std::vector<CardComponent> cards; // Holds the cards in the hand as a vector of CardComponents
};

// Struct representing a component for holding a score
struct ScoreComponent
{
    int score;
};

struct InputComponent
{
    std::string input;
};
