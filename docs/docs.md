# Blackjack Game Documentation

## Introduction
This documentation provides an overview of the architecture, codebase, and development process of the Blackjack game developed by Emil and Ossian.

## Architecture
The Blackjack game follows a simple architecture based on the Entity-Component-System (ECS) pattern:

- **Entity:** Represents a game object, such as a player or a card.
- **Components:** Define the properties and behavior of entities, such as cards having a rank and suit.
- **System:** Implements game logic and behavior, such as dealing cards, evaluating hands, and managing turns.

## Codebase
The codebase of the Blackjack game is organized into logical components:

- **Main:** Contains the entry point of the game and initializes necessary systems.
- **Components:** Defines various game components, such as cards, hands, scores, and the deck.
- **Systems:** Implements game systems, such as dealing cards, evaluating hands, managing turns, and displaying UI.
- **UI:** Handles UI rendering and interaction, including displaying game state and processing player input.

## Development Process
The development of the Blackjack game followed an iterative and collaborative process:

- **Planning:** Emil and Ossian started by defining the game's requirements, including rules, features, and UI design. They created a roadmap to guide development.
- **Implementation:** Tasks were divided between Emil and Ossian to make development easier and more efficient. Ossian worked on creating the entities, components, and defined system, while Emil worked on the systems and UI. Both developers worked on all tasks.
- **Deployment:** Once the game reached a stable state, it was deployed for public access.

