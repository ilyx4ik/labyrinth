#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

void drawMap(vector<vector<int>> &arr, int hp) {
    system("cls");
    cout << "HP: " << hp << " / 100" << endl;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j] == 0) cout << ". ";
            else if (arr[i][j] == 1) cout << "# ";
            else if (arr[i][j] == 2) cout << "P ";
            else if (arr[i][j] == 3) cout << "E ";
            else if (arr[i][j] == 4) cout << "X ";
            else if (arr[i][j] == 5) cout << "+ ";
        }
        cout << endl; 
    }
}

bool checkGameStatus(vector<vector<int>> &arr, int playerX, int playerY, int hp) {
    if (playerX == arr.size() - 1 && playerY == arr[0].size() - 2) {
        cout << "====================" << endl;
        cout << "You win! " << endl;
        cout << "====================" << endl;
        return true;
    }
    if (hp <= 0) {
        cout << "====================" << endl;
        cout << "You are dead! " << endl;
        cout << "====================" << endl;
        return true;
    }
    return false;
}

void stepOnCell(vector<vector<int>> &arr, int playerX, int playerY, int &hp) {
    if (arr[playerX][playerY] == 4) hp -= 35; 
    if (arr[playerX][playerY] == 5) hp = min(100, hp + 35); 
    arr[playerX][playerY] = 2;
}

void handleMovement(char move, vector<vector<int>> &arr, int &playerX, int &playerY, int &hp) {
    switch (move) {
        case 'w': case 'W':
            if (playerX > 0 && arr[playerX - 1][playerY] != 1) {
                arr[playerX][playerY] = 0;
                playerX--; 
                stepOnCell(arr, playerX, playerY, hp);
            }
            break; 

        case 'a': case 'A':
            if (playerY > 0 && arr[playerX][playerY - 1] != 1) {
                arr[playerX][playerY] = 0;
                playerY--; 
                stepOnCell(arr, playerX, playerY, hp);
            }
            break; 

        case 's': case 'S':
            if (playerX < arr.size() - 1 && arr[playerX + 1][playerY] != 1) {
                arr[playerX][playerY] = 0;
                playerX++; 
                stepOnCell(arr, playerX, playerY, hp);
            }
            break;

        case 'd': case 'D':
            if (playerY < arr[0].size() - 1 && arr[playerX][playerY + 1] != 1) {
                arr[playerX][playerY] = 0;
                playerY++; 
                stepOnCell(arr, playerX, playerY, hp);
            }            
            break;
    } 
}

int main() {
    int rows, cols;
    cout << "Enter the map height: ";
    cin >> rows;
    cout << "Enter the map width: ";
    cin >> cols;
    if (rows < 3) rows = 5;
    if (cols < 3) cols = 4;
    vector<vector<int>> arr(rows, vector<int>(cols, 0));
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == 0 && j == 1) || (i == rows - 1 && j == cols - 2)) {
                continue;
            }

    int chance = rand() % 100;
    if (chance < 20) {
        arr[i][j] = 1;
    } else if (chance < 30) {
        arr[i][j] = 4;
    } else if (chance < 35) {
        arr[i][j] = 5;
    } else {
        arr[i][j] = 0;
    }
}
    }
    int playerX = 0;
    int playerY = 1;
    arr[playerX][playerY] = 2;
    int hp = 100;
    char move;

    arr[rows - 1][cols - 2] = 3;
    if (rows > 3 && cols > 3) {
        arr[1][cols - 2] = 4;
        arr[2][1] = 5;
    }

    while (true) {   
        drawMap(arr, hp);

        if (checkGameStatus(arr, playerX, playerY, hp)) break;
        
        cout << "Enter move (WASD): ";
        cin >> move;

        if (move == 'q' || move == 'Q') {
            cout << "Exiting game." << endl;
            break;
        } 

        handleMovement(move, arr, playerX, playerY, hp);
    }
    return 0;
}
