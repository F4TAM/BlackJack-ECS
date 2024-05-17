# User Documentation: Blackjack ECS

## Overview

This user documentation provides a comprehensive guide to playing Blackjack ECS, a C++ implementation of the classic card game Blackjack utilizing the Entity Component System (ECS) architecture. Whether you're new to the game or seeking clarification on advanced strategies, this guide will assist you in understanding the rules, installation process, gameplay, and troubleshooting.

---

### Table of Contents

1. **[Installation Guide](#installation-guide)**
2. **[Gameplay Guide](#gameplay-guide)**
3. **[Frequently Asked Questions](#frequently-asked-questions)**
4. **[Contact Information](#contact-information)**

---

### 1. Installation Guide

#### System Requirements

- C++ compiler supporting C++11 or higher.
- Standard Template Library (STL).
- Command-line interface (CLI) or Integrated Development Environment (IDE).

#### Steps to Install

1. **Clone the Repository**: Download or clone the Blackjack ECS repository from [GitHub](https://github.com/F4TAM/BlackJack-ECS/) to your local machine.

2. **Build the Project**:
   - Navigate to the root directory of the project in your CLI or IDE.
   - Execute the build command appropriate for your system. For example using bash:
     ```bash
     g++ main.cpp -o blackjack
     ```
3. **Run the Executable**:
   - After a successful build, run the generated executable:
     ```bash
     ./blackjack
     ```

---

### 2. Gameplay Guide

#### Starting the Game

- Launch the game executable.
- Follow the on-screen prompts to start a new round of Blackjack.

#### Game Controls

- Use the keyboard to interact with the game.
- Follow the prompts to select actions such as hitting, standing, doubling down, or surrendering.

#### Objective

- The objective of Blackjack is to obtain a hand value as close to 21 as possible without exceeding it.
- Beat the dealer's hand without busting (exceeding 21) to win.

#### Scoring and Winning

- Aces are worth 11 points, face cards (Jack, Queen, King) count as 10 points, and all other cards count as their numerical value.
- Blackjack (an Ace with a 10-value card) results in an automatic win unless the dealer also has Blackjack which draws the game.
- The player wins if their hand total is closer to 21 than the dealer's hand without going over.

---

### 3. Frequently Asked Questions

#### Q: How is the winner determined in Blackjack?

- A: The winner is determined by comparing the total value of the player's hand to the dealer's hand. The hand closest to 21 without exceeding it wins. In case of a tie, it's a push (no winner).

#### Q: Can I adjust the bet amount in the game?

- A: The current implementation does not include betting functionality. It's focused solely on the gameplay mechanics of Blackjack.

#### Q: How can I exit the game?

- A: Simply close the game window or press the designated exit key (if specified in the game).

---

### 4. Contact Information

For additional assistance, feedback, or bug reports, please visit the GitHub repository at [our respository](https://github.com/F4TAM/BlackJack-ECS/) and open an issue. We appreciate your contributions and suggestions to enhance the Blackjack ECS experience.

---
```