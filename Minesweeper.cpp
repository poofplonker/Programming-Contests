//
//  Minesweeper.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 29/06/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
using namespace std;

bool isValid(int i, int j, int rows, int cols){
    if(i >=0 && i < rows && j >=0 && j <cols){
        return true;
    }
    return false;
}

void incrementNeighbours(int **adjMatrix, int x, int y, int rows, int cols){
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (isValid(x+i, y+j, rows, cols)) {
                adjMatrix[x+i][y+j]++;
            }
        }
    }
}




int main(void){
    int rows, cols;
    int counter = 0;
    bool first = true;
    while (cin >> rows >> cols) {
        if (!cols && !rows) {
            return 0;
        }
        counter++;
        int** adjMatrix = new int*[rows];
        for (int i =0 ; i < rows; i++) {
            adjMatrix[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                adjMatrix[i][j] = 0;
            }
        }
        char input;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> input;
                if(input == '*'){
                    incrementNeighbours(adjMatrix, i,j,rows,cols);
                    adjMatrix[i][j] = -100;
                }
            }

        }
        
        if(!first){
            cout << endl;
        }
        first = false;
        cout << "Field #" << counter << ":"<<endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (adjMatrix[i][j] >= 0) {
                    cout << adjMatrix[i][j];
                }else{
                    cout << '*';
                }
            }
            cout << endl;
        }
        
        for (int i = 0; i < rows; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
}

