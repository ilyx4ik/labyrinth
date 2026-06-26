# 🎮 Console Procedural Survival Game in C++ (Vector Version)

A dynamic, console-based text survival game written in C++. The player must navigate through a procedurally generated labyrinth filled with hidden traps, manage their Health Points (HP), and reach the exit point.

This version represents a major milestone, shifting from static arrays to **dynamic memory management via `std::vector`** and introducing **procedural map generation**.

---

## 🕹️ Gameplay & Map Elements

The game board is dynamically generated based on user input. Each symbol represents a specific game element:

| Symbol | Meaning | Element Description |
| :---: | :--- | :--- |
| **`P`** | **Player** | Your character. Starts at the top-left corner `(0, 1)`. |
| **`E`** | **Exit** | The finish line. Dynamically placed at the bottom-right. Reach it to win! |
| **`#`** | **Wall** | Impassable obstacle generated with a 20% chance per cell. |
| **`.`** | **Empty space**| A safe path you can move onto. |
| **`X`** | **Mine** | Hidden trap (10% spawn chance). Stepping here deals **-35 HP**. |
| **`+`** | **First Aid Kit**| Healing item (5% spawn chance). Restores **+35 HP** (capped at 100 HP). |

---

## ⚙️ Controls

Character movement is handled via standard console input (type the character and press `Enter`):

* **`W` / `w`** — Move Up
* **`A` / `a`** — Move Left
* **`S` / `s`** — Move Down
* **`D` / `d`** — Move Right
* **`Q` / `q`** — Quit the game instantly

---

## 🚀 Technical Highlights & Advanced Architecture

The codebase has been refactored to meet production-level standards:

* **Dynamic Grid via STL Vectors:** Replaced raw arrays `int arr[5][4]` with `std::vector<std::vector<int>>`. The game no longer relies on hardcoded sizes and can scale to any dimensions (e.g., 10x10, 20x20) at runtime.
* **Procedural Generation (`<ctime>`):** Map layout is seeded using `srand(time(0))`. Walls, mines, and health kits are distributed using a probability-based distribution algorithm, ensuring a unique map layout on every launch.
* **Smart Boundary & Index Evaluation:** Out-of-bounds checks and win conditions dynamically adapt using the `.size()` and `.size() - 1` matrix calculations, preventing memory leaks and buffer overflows.
* **Pass-by-Reference (`&`):** Large matrix data structures are passed by reference to avoid expensive memory copying operations between functions (`drawMap`, `handleMovement`, etc.).
