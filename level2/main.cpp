/*
 * Team Podurile Valea Largă
 * Members:
 *  Alex Trifan
 *  Darius Stoica
 *  Denisa Solniceanu
 * ---------------------------
 *  Cloudflight Coding Contest
 *  2022 Nov. Edition
 * */

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.in");
ofstream fout("input.out");

int N, coins;//number of lines and columns
char matrix[100][100];
int pacman_i, pacman_j, seqlenght, valid[100][100];
char seq[100];

void readMatrix(){
    fin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            fin >> matrix[i][j];
    fin >> pacman_i >> pacman_j;//save the starting position of Pacman
    fin >> seqlenght;
    for(int i = 0; i < seqlenght; i++)
        fin >> seq[i];//save the list of orders for Pacman
}

int Parcurgere(){
    for(int i = 0; i < seqlenght; i++) {
        if (seq[i] == 'L')
            if (matrix[pacman_i][pacman_j - 1] == 'C' and valid[pacman_i][pacman_j - 1] == 0) {
                coins++;
                valid[pacman_i][pacman_j - 1] = 1;
                pacman_j--;
            }//moving Pacman to the Left

        if(seq[i] == 'R')
            if (matrix[pacman_i][pacman_j + 1] == 'C' and valid[pacman_i][pacman_j + 1] == 0) {
                coins++;
                valid[pacman_i][pacman_j + 1] = 1;
                pacman_j++;
            }//moving Pacman to the Right

        if(seq[i] == 'U')
            if (matrix[pacman_i - 1][pacman_j] == 'C' and valid[pacman_i - 1][pacman_j] == 0) {
                coins++;
                valid[pacman_i - 1][pacman_j] = 1;
                pacman_i--;
            }//moving Pacman to Up

        if(seq[i] == 'D')
            if (matrix[pacman_i + 1][pacman_j] == 'C' and valid[pacman_i + 1][pacman_j] == 0) {
                coins++;
                valid[pacman_i + 1][pacman_j] = 1;
                pacman_i++;
            }//moving Pacman to Down
    }
    return coins;
}

int main() {
    readMatrix();
    fout << Parcurgere();
    return 0;
}