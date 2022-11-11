/*
 * Team Podurile Valea Largă
 * Members:
 *  Alex Trifan
 *  Denisa Stolniceanu
 *  Darius Stoica
 * ---------------------------
 *  36th Cloudflight Coding Contest
 *  2022 Nov. Edition
 * */
#include <iostream>
#include <cstring>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("input.in");
ofstream fout("input.out");

int N;//number of lines and columns
char matrix[100][100];
int pacman_i, pacman_j;

void readMatrix(){
    fin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            fin >> matrix[i][j];
            if (matrix[i][j] == 'P'){
                pacman_i = i;
                pacman_j = j;
            }//saving the starting position for Pacman
        }
}

bool isInTheMatrix(char matrix[][100], int i, int j){
    if (i == pacman_i and j == pacman_j)
        return false;
    if(matrix[i][j] == 'W')
        return false;//Pacman can't hit a wall
    if(i < 0 and i > N and j < 0 and j > N)
        return false;
    return true;
}

int dl[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
queue<int> X, Y;
int coins;//the number of coins Pacman colects

void Lee() {
    X.push(pacman_i);
    Y.push(pacman_j);
    matrix[pacman_i][pacman_j] = 'W';
    int x, y, xx, yy;
    while (!X.empty()) {
        x = X.front();
        y = Y.front();
        for (int i = 0; i < 4; i++) {
            xx = x + dl[i];
            yy = y + dc[i];
            if (isInTheMatrix(matrix,xx, yy)) {
                X.push(xx);
                Y.push(yy);
                coins++;
                matrix[xx][yy] = 'W';//mark the colected coins as walls
            }
        }
        X.pop();
        Y.pop();
    }
}

int main() {
    readMatrix();
    Lee();
    fout << coins;
    return 0;
}
