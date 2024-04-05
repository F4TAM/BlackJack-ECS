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
	auto hand = entity->getComponent<HandComponent>(); // get hand component from entity

	// Display the names of dealer and player and their cards 
	displayText(entity->getComponent<NameComponent>()->name + " Cards: ");

	// Display the hidden card of the dealer
	if (entity->getComponent<NameComponent>()->name == "Dealer")
	{
		std::cout << "Hidden Card\n"; // Display hidden card

		// Display the rest of the cards
		for (int i = 1; i < hand->cards.size(); ++i) {
			auto& card = hand->cards[i]; // get reference to card
			std::cout << card.rank << " of " << card.suit << "\n";
		}
		return;
	}

	// Display the cards of the player
	for (int i = 0; i < hand->cards.size(); ++i) {
		auto& card = hand->cards[i]; // get reference to card
		std::cout << card.rank << " of " << card.suit << "\n";
	}
}
// Display the scores of the player or dealer
void UISystem::displayScores(Entity* entity)
{
	auto entityScore = entity->getComponent<ScoreComponent>();
	auto entityName = entity->getComponent<NameComponent>();
	
	std::cout << "Your Score: " << entityScore->score << "\n";
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
		std::cout << "Dealer wins with a score of " << dealerScore->score << "!\n";
		std::cout << "Player's Score: " << playerScore->score << "\n";
	}
	else if(dealerScore->score > 21)
	{
		std::cout << "Dealer has busted!\n";
		std::cout << "Player wins with a score of " << playerScore->score << "!\n";
		std::cout << "Dealer's Score: " << dealerScore->score << "\n";
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
void DeckSystem::dealCard(Entity* deck, Entity* entity, int amount)
{
   auto cards = deck->getComponent<DeckComponent>();
   auto hand = entity->getComponent<HandComponent>();

   for (int i = 0; i < amount; i++)
   {
	   hand->cards.push_back(*cards->cards.back());
	   cards->cards.pop_back();
   }

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
// Calculate the score of the player and dealer
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
// clearing the cards, scores, and input for restart
void BlackjackSystem::restart(Entity* player, Entity* dealer, Entity* deck)
{
	// Clear the cards from the player and dealer hands
	player->getComponent<HandComponent>()->cards.clear();
	dealer->getComponent<HandComponent>()->cards.clear();

	// Clear the scores of the player and dealer
	player->getComponent<ScoreComponent>()->score = 0;
	dealer->getComponent<ScoreComponent>()->score = 0;

	// Clear the stand status of the player and dealer
	player->getComponent<StandComponent>()->stand = false;
	dealer->getComponent<StandComponent>()->stand = false;

	// Clear the input of the player and dealer
	player->getComponent<InputComponent>()->input = "";

	// Clear the deck of cards
	deck->getComponent<DeckComponent>()->cards.clear();
}
