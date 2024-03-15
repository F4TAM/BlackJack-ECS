#pragma once

#include <string>
#include <vector>

struct NameComponent
{
    std::string name;
};

struct HandComponent
{
    std::vector<std::string> cards;
};

struct CardComponent
{
    std::string suit, color;
    int value; 
};

struct ScoreComponent
{
    int score;
};
