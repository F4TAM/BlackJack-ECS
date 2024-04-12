# Developer Documentation

## Comprehensive Guide to Blackjack Game Development with ECS and C++

This section presents an in-depth developer documentation for the Blackjack Game. This game, developed using C++ and incorporating the Entity Component System (ECS) architecture, showcases a structured approach to game development. The complete source code is accessible [here](<https://github.com/F4TAM/BlackJack-ECS>).

---

### Developer Documentation for Blackjack Game

#### Table of Contents
1. **[Introduction](#1-introduction)**
2. **[Technical Specifications and Design](#2-technical-specifications-and-design)**
3. **[Architectural Overview](#3-architectural-overview)**
    - 3.1. [Class Diagrams](#31-class-diagrams)
    - 3.2. [Entities and Components](#32-entities-and-components)
    - 3.3. [Systems](#33-systems)
4. **[Development Guidelines and Standards](#4-development-guidelines-and-standards)**
5. **[Testing Framework and Coverage](#5-testing-framework-and-coverage)**
6. **[Versioning Information](#6-versioning-information)**
7. **[Accessibility in Game Design](#8-accessibility-in-game-design)**
8. **[Troubleshooting and FAQs](#9-troubleshooting-and-faqs)**
9. **[References and Further Reading](#11-references-and-further-reading)**


---

#### 1. Introduction

This documentation provides a comprehensive guide to the development of the Blackjack Game using C++ and the ECS architecture. It aims to assist developers in understanding the project structure, contributing to it, and extending its functionality.

---

#### 2. Technical Specifications and Design

- **ECS Framework**:
  - **Entities**: Includes entities like Player and Dealer, each represented as an instance of `Entity`.
  - **Components**: Encompasses components such as `HandComponent` for managing player hands and `CardComponent` for representing individual cards.
  - **Systems**: Consists of systems like `BlackjackSystem` for game logic and `UISystem` for graphical representation.

- **Game Logic**:
  - Implements standard Blackjack rules including player actions like Hit and Stand.
  - Utilizes a deck of cards represented as a deck Entity by the ECS.

---

#### 3. Architectural Overview

- ### 3.1. Class Diagrams
- ECS Architecture Flowchart
![ECS Architecture Flowchart](<https://i.ibb.co/SNKszfB/chart-programmering.jpg>)
  

- **3.2. Entities and Components**
  - **Entities**:
    - `PlayerEntity`: Represents a player in the game.
    - `DealerEntity`: Represents the dealer.
    - `DeckEntity`: Represents a deck of cards.
  - **Components**:
    - `HandComponent`: Manages the hand of a player or the dealer.
    - `CardComponent`: Represents a single card, storing its value and suit.
    - `InputComponent`: represents a input holder. 
    - `StandComponent`: Represeting a component wheter a player stands or not.
    - `NameComponent`: Represents a component for holding a player name.
    - `UIComponent`: Represents a component for holding UI output.
    - `DeckComponent`: Represents a component for holding a deck of cards.

- **3.3. Systems**
  - **BlackjackSystem**: Handles the game logic including dealing cards, player actions, and determining the winner.
  - **UISystem**: Responsible for rendering game elements such as cards and player hands.
  - **DeckSystem**: Handles decks and cards to give to entities.

---

#### 4. Development Guidelines and Standards

- **ECS Adherence**: Follow the ECS architecture strictly for any modifications or additions to the game.
- **Modularity**: Ensure modularity in development to facilitate scalability and maintainability.
- **Code Standards**: Adhere to C++ coding standards for clarity and consistency.

---

#### 5. Testing Framework and Coverage

- **Unit Testing**: Focuses on testing individual components and systems to ensure functionality and reliability.
- **Integration Testing**: Test the interaction between systems to verify the overall behavior of the game.
- **Code Coverage**: Utilize code coverage tools to assess the effectiveness of testing strategies.

---

#### 6. Versioning Information

- **Game Version**: 1.0.0
- **C++ Version**: C++17 or higher
- **ECS Framework**: Custom ECS implementation or any available ECS library used.

---

#### 7. Accessibility in Game Design

- CLI based game design

---

#### 8. Troubleshooting and FAQs

- **Q: What if the game crashes unexpectedly?**
  - A: Check if all files are downloaded and check for memory leaks or errors

---


#### 9. References

1. ECS Documentation: [https://replit.com/@nti-tillmpat-programmering-2/ECSGameDev-1-nti-tillmpat-programmering-2-7].


