#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <fstream>
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
            else if (arr[i][j] == 6) cout << "K ";
        }
        cout << endl; 
    }
}

void SaveMapToFile(vector<vector<int>> &arr) {
    ofstream outFile("map.txt");
    if(!outFile.is_open()){
        cout << "Error: could'nt save the map!" << endl;
        system("pause");
        return;
    }

    outFile << arr.size() << " " << arr[0].size() << endl;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            outFile << arr[i][j] << " ";
        }
        outFile << endl;
    }

    outFile.close();
    cout << "Map have been saved" << endl;
    system("pause");
}

bool LoadMapFromFile (vector<vector<int>> &arr, int &playerX, int &playerY) {
    ifstream inFile("map.txt");
    if(!inFile.is_open()) {
        cout << "Error: could'nt open the map!" << endl;
        system("pause");
        return false;
    }

    int fileRows = 0, fileCols = 0;

    inFile >> fileRows >> fileCols;

    arr.assign(fileRows, vector<int>(fileCols, 0));

    for (int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            inFile >> arr[i][j];

            if (arr[i][j] == 2) {
                playerX = i;
                playerY = j;
            }
        }
    }
    inFile.close();
    return true;
}

bool checkGameStatus(vector<vector<int>> &arr, int playerX, int playerY, int hp, bool hasKey, int exitX, int exitY) {
    if (playerX == exitX && playerY == exitY && hasKey) {
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

void stepOnCell(vector<vector<int>> &arr, int playerX, int playerY, int &hp, bool &hasKey) {
    if (arr[playerX][playerY] == 6) hasKey = true;
    if (arr[playerX][playerY] == 4) hp -= 35; 
    if (arr[playerX][playerY] == 5) hp = min(100, hp + 35); 
    arr[playerX][playerY] = 2;
}

void handleMovement(char move, vector<vector<int>> &arr, int &playerX, int &playerY, int &hp, bool &hasKey, int exitX, int exitY) {
    switch (move) {
        case 'w': case 'W':
            if (playerX > 0 && arr[playerX - 1][playerY] != 1) {
                arr[playerX][playerY] = (playerX == exitX && playerY == exitY) ? 3 : 0; 
                playerX--; 
                stepOnCell(arr, playerX, playerY, hp, hasKey);
            }
            break; 

        case 'a': case 'A':
            if (playerY > 0 && arr[playerX][playerY - 1] != 1) {
                arr[playerX][playerY] = (playerX == exitX && playerY == exitY) ? 3 : 0;
                playerY--; 
                stepOnCell(arr, playerX, playerY, hp, hasKey);
            }
            break; 

        case 's': case 'S':
            if (playerX < arr.size() - 1 && arr[playerX + 1][playerY] != 1) {
                arr[playerX][playerY] = (playerX == exitX && playerY == exitY) ? 3 : 0;
                playerX++; 
                stepOnCell(arr, playerX, playerY, hp, hasKey);
            }
            break;

        case 'd': case 'D':
            if (playerY < arr[0].size() - 1 && arr[playerX][playerY + 1] != 1) {
                arr[playerX][playerY] = (playerX == exitX && playerY == exitY) ? 3 : 0;
                playerY++; 
                stepOnCell(arr, playerX, playerY, hp, hasKey);
            }            
            break;
    } 
}

int main() {
    bool hasKey = false;
    int rows, cols;
    
    cout << "Enter the map height: ";
    cin >> rows;
    cout << "Enter the map width: ";
    cin >> cols;
    
    if (rows < 4) rows = 5; 
    if (cols < 4) cols = 5;
    
    vector<vector<int>> arr(rows, vector<int>(cols, 0));
    srand(time(0));
    
    int playerX = 0;
    int playerY = 1;

    char choice;
    cout << "Do you want load the saved map? (y/n) ";
    cin >> choice;

    bool loaded = false;
    if (choice == 'y' || choice == 'Y') {
        loaded = LoadMapFromFile(arr, playerX, playerY);
    }

    if (!loaded) {
        cout << "Generating new random map" << endl;
        system("pause");

        int tempExitX = rows - 1;
        int tempExitY = cols - 2;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 1) ||
                    (i == tempExitX && j == tempExitY) || (i == tempExitX - 1 && j == tempExitY) || (i == tempExitX && j == tempExitY - 1)) {
                    continue;
                }

                int chance = rand() % 100;
                if (chance < 20) {
                    arr[i][j] = 1;
                } else if (chance < 25) {
                    arr[i][j] = 6;
                } else if (chance < 35) {
                    arr[i][j] = 4;
                } else if (chance < 40) {
                    arr[i][j] = 5;
                } else {
                    arr[i][j] = 0;
                }
            }
        }
        
        playerX = 0;
        playerY = 1;
        arr[playerX][playerY] = 2;
        arr[tempExitX][tempExitY] = 3; 
    } 

    int exitX = arr.size() - 1;
    int exitY = arr[0].size() - 2;

    int hp = 100;
    char move;

    while (true) {   
        drawMap(arr, hp);

        if (checkGameStatus(arr, playerX, playerY, hp, hasKey, exitX, exitY)) break;
        
        cout << "Enter move (WASD): ";
        cin >> move;

        if (move == 'q' || move == 'Q') {
            cout << "Exiting game." << endl;
            break;
        } 

        if (move == 'p' || move == 'P') {
            SaveMapToFile(arr);
            continue;
        }

        handleMovement(move, arr, playerX, playerY, hp, hasKey, exitX, exitY);
    }
    return 0;
}
