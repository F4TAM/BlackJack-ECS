#include "system.h"
#include <iostream>



void UISystem::takeInput(Entity* entity)
{
    auto input = entity->getComponent<InputComponent>();
    //take input
    std::cin >> input->input;
}
// Display the cards of the player or dealer
void UISystem::displayCards(Entity* entity)
{
    entity->getComponent<HandComponent>();
    for (auto card : entity->getComponent<HandComponent>()->cards)
    {
		std::cout << card.rank << " of " << card.suit << "\n";
	}
}
// Display the scores of the player or dealer
void UISystem::displayScores(Entity* player, Entity* dealer)
{
	auto playerScore = player->getComponent<ScoreComponent>();
	auto dealerScore = dealer->getComponent<ScoreComponent>();

	std::cout << "Player Score: " << playerScore->score << "\n";
	std::cout << "Dealer Score: " << dealerScore->score << "\n";
}
// Display the winner of the game
void UISystem::displayWinner(Entity* player, Entity* dealer)
{
	auto playerScore = player->getComponent<ScoreComponent>();
	auto dealerScore = dealer->getComponent<ScoreComponent>();

	if (playerScore->score == 21 && dealerScore->score == 21)
	{
		std::cout << "Both player and dealer have a blackjack! It's a Tie!\n";
	}
	else if(playerScore->score == 21)
	{
		std::cout << "Player wins with a blackjack!\n";
	}
	else if(dealerScore->score == 21)
	{
		std::cout << "Dealer wins with a blackjack!\n";
	}
	else if(playerScore->score > 21)
	{
		std::cout << "Player has busted!\n";
	}
	else if(dealerScore->score > 21)
	{
		std::cout << "Dealer has busted!\n";
	}
	else if(playerScore->score > dealerScore->score)
	{
		std::cout << "Player wins with a score of " << playerScore->score << "!\n";
	}
	else if(dealerScore->score > playerScore->score)
	{
		std::cout << "Dealer wins with a score of " << dealerScore->score << "!\n";
	}
	else
	{
		std::cout << "It's a Tie!\n";
	}
}
// Clear the console
void UISystem::displayClear()
{
    std::cout << "\033[2J\033[1;1H";
    //Clears console
}
// Display text to the console
void UISystem::displayText(std::string text)
{
    std::cout << text << "\n";
}
// Initialize the deck with 52 cards
void DeckSystem::initDeck(Entity* deck)
{
    CardComponent cardComponent;
    //Define the suits and ranks of the cards
    std::string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    std::string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    for (auto suit : suits)
    {
        for (auto rank : ranks)
        {
			cardComponent.suit = suit;
			cardComponent.rank = rank;
            //Add the card to the deck
			deck->getComponent<DeckComponent>()->cards.push_back(std::make_unique<CardComponent>(cardComponent));
		}
	}
}
// Deal a card to the player or dealer
void DeckSystem::dealCard(Entity* deck, Entity* entity)
{
   auto cards = deck->getComponent<DeckComponent>();
   auto hand = entity->getComponent<HandComponent>();

   //Randomly select a card from the deck and add it to the hand
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(0, cards->cards.size() - 1);
   hand->cards.push_back(*cards->cards[dis(gen)]);
   cards->cards.erase(cards->cards.begin() + dis(gen));

}
// Shuffle the deck
void DeckSystem::shuffleDeck(Entity* deck)
{
    // Get the deck component from the entity
	auto cards = deck->getComponent<DeckComponent>();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(cards->cards.begin(), cards->cards.end(), gen);
}

void BlackjackSystem::calculateScore(Entity* player, Entity* dealer)
{
		// Get the hand component from the player and dealer
		auto playerHand = player->getComponent<HandComponent>();
		auto dealerHand = dealer->getComponent<HandComponent>();

		// Get the score component from the player and dealer
		auto playerScore = player->getComponent<ScoreComponent>();
		auto dealerScore = dealer->getComponent<ScoreComponent>();

		// Calculate the score of the player and dealer
		playerScore->score = 0;
		for (auto card : playerHand->cards)
		{
			if (card.rank == "Jack" || card.rank == "Queen" || card.rank == "King")
			{
				playerScore->score += 10;
			}
			else if (card.rank == "Ace")
			{
				playerScore->score += 11;
			}
			else
			{
				playerScore->score += std::stoi(card.rank);
			}
		}

		dealerScore->score = 0;
		for (auto card : dealerHand->cards)
		{
			if (card.rank == "Jack" || card.rank == "Queen" || card.rank == "King")
			{
				dealerScore->score += 10;
			}
			else if (card.rank == "Ace")
			{
				dealerScore->score += 11;
			}
			else
			{
				dealerScore->score += std::stoi(card.rank);
			}
		}

}
