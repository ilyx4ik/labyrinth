# 🎮 Console Micro-Survival Game in C++ (Refactored Version)

A modular, console-based text survival game written in C++. The player must navigate a character through a dangerous grid filled with hidden traps and reach the exit point while keeping their Health Points (HP) above zero.

This updated version represents a complete architectural overhaul, shifting from global variables to **local state management** and **pass-by-reference (`&`)** mechanics.

---

## 🕹️ Gameplay & Map Elements

The game board is a 2D grid where each symbol represents a specific game element:

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

## 🚀 Technical Highlights & Clean Code Architecture

The codebase has been thoroughly refactored to comply with industry-standard production practices:

* **Zero Global Variables:** All critical game states (`arr`, `hp`, `playerX`, `playerY`) are securely encapsulated inside the `main()` function scope.
* **Pass-by-Reference (`&`):** Functions like `handleMovement()` and `stepOnCell()` utilize C++ references to modify the original game state directly in memory without costly and buggy data copying.
* **Strict DRY Principle:** Redundant map-trigger checks within the execution blocks were extracted into an isolated `stepOnCell()` helper function.

### Function Breakdown:
* `drawMap(int arr[5][4], int hp)` — Renders the map and HUD by reading local parameters.
* `checkGameStatus(int x, int y, int hp)` — Evaluates coordinates to trigger win/loss screens.
* `handleMovement(char move, int arr[5][4], int &x, int &y, int &hp)` — Processes input and securely modifies coordinates and health using references.
