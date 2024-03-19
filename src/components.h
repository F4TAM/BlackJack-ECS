
#pragma once // Prevents multiple inclusions of this header file

#include <string> // Includes the string class for handling strings
#include <vector> // Includes the vector class for handling dynamic arrays
#include <memory> // Includes the memory class for handling smart pointers


// Struct representing a component for holding a name
struct NameComponent
{
    std::string name;
};

struct InputComponent
{
	std::string input;
};

// Struct representing a component for holding information about a single card
struct CardComponent
{
    std::string suit, rank;
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

struct UIComponent
{
	std::string output;
};

struct DeckComponent
{
    std::vector<std::unique_ptr<CardComponent>> cards;
};