# # 🎮 Console Micro-Survival Game in C++

A simple yet engaging console-based text survival game written in C++. The player must navigate a character through a dangerous grid filled with hidden mines and reach the exit point while keeping their Health Points (HP) above zero.

This project demonstrates the core principles of procedural programming, working with 2D arrays, control flow structures (`switch-case`, `while`), and clean code refactoring by breaking game logic into independent functions.

---

## 🕹️ Gameplay & Map Elements

The game board is a grid where each symbol represents a specific game element:

| Symbol | Meaning | Element Description |
| :---: | :--- | :--- |
| **`P`** | **Player** | Your character. Starts at the top-left corner. |
| **`E`** | **Exit** | The finish line. Reach this spot to win the game! |
| **`#`** | **Wall** | An impassable obstacle. You cannot walk through walls. |
| **`.`** | **Empty space**| A safe, empty cell you can move onto. |
| **`X`** | **Mine** | A hidden trap! Stepping here deals **-35 HP**. |
| **`+`** | **First Aid Kit**| A healing item. Restores **+35 HP** (capped at 100 HP). |

---

## ⚙️ Controls

Character movement is handled via standard console input (type the character and press `Enter`):

* **`W` / `w`** — Move Up
* **`A` / `a`** — Move Left
* **`S` / `s`** — Move Down
* **`D` / `d`** — Move Right
* **`Q` / `q`** — Quit the game instantly

---

## 🚀 Getting Started

To run this game, you will need a C++ compiler (such as GCC, Clang, or MSVC) or an IDE (Visual Studio, VS Code, CLion).

1. Clone this repository or download the source code files.
2. Open your terminal/command prompt in the project directory.
3. Compile the code using the following command:
   ```bash
   g++ -O3 main.cpp -o survival_game