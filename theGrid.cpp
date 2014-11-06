//
//  theGrid.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 22/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int grid[10][10];
int n;

bool checkMin(int row, int* chosen, int b){
    int minScore = 10000;
    int minIndex = 0;
    for (int i = 0; i < n; i++) {
        if(chosen[i] == 0 && grid[row][i] < minScore){
            minScore = grid[row][i];
            minIndex = i;
        }
    }
    chosen[minIndex] = 1;
    //cout << minScore << " is smallest" << endl;
    if(grid[row][minIndex] == grid[row][b]){
        return true;
    }
    return false;
}
int main(void){
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        cin >> n;
        int perm[10];
        int colChosen[10];
        for (int i = 0; i < n; i++) {
            perm[i] = i;
            colChosen[i] = 0;
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        int maxScore = -1000000;
        do{
            int permB[10];
            for (int i = 0; i < n; i++) {
                colChosen[i] = 0;
                permB[i] = i;
            }
            do{
                for (int i = 0; i < n; i++) {
                    colChosen[i] = 0;
                }
                int score = 0;
                bool valid = true;
                for (int i = 0; i < n; i++) {
                    if (checkMin(perm[i], colChosen,permB[i])) {
                        score += grid[perm[i]][permB[i]];
                    }else{
                        valid = false;
                        break;
                    }
                }
                if(valid && score > maxScore){
                    maxScore = score;
                }
            }while(next_permutation(permB, permB+n));
        }while (next_permutation(perm,perm+n));
        cout << maxScore << endl;
    }
}
