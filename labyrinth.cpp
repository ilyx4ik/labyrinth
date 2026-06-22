#include <iostream>
#include <algorithm> 
using namespace std;

void drawMap(int arr[5][4], int hp) {
    system("cls");
    cout << "HP: " << hp << " / 100" << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
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

bool checkGameStatus(int playerX, int playerY, int hp) {
    if (playerX == 4 && playerY == 2) {
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

void stepOnCell(int arr[5][4], int playerX, int playerY, int &hp) {
    if (arr[playerX][playerY] == 4) hp -= 35; 
    if (arr[playerX][playerY] == 5) hp = min(100, hp + 35); 
    arr[playerX][playerY] = 2;
}

void handleMovement(char move, int arr[5][4], int &playerX, int &playerY, int &hp) {
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
            if (playerX < 4 && arr[playerX + 1][playerY] != 1) {
                arr[playerX][playerY] = 0;
                playerX++; 
                stepOnCell(arr, playerX, playerY, hp);
            }
            break;

        case 'd': case 'D':
            if (playerY < 3 && arr[playerX][playerY + 1] != 1) {
                arr[playerX][playerY] = 0;
                playerY++; 
                stepOnCell(arr, playerX, playerY, hp);
            }            
            break;
    } 
}

int main() {
    int arr[5][4] = {
        {1, 2, 0, 1},
        {1, 4, 0, 1},
        {1, 5, 0, 1},
        {1, 0, 4, 1},
        {1, 4, 3, 1}
    };
    int hp = 100;
    int playerX = 0;
    int playerY = 1;
    char move;

    while (true) {   
        drawMap(arr, hp);

        if (checkGameStatus(playerX, playerY, hp)) break;
        
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
