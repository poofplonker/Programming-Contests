//
//  waldorf.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 15/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool possible(int rows, int cols, int r, int v, int x, int y, int size){
    int colEnd = v + (y*size);
    int rowEnd = r + (x*size);
    if (colEnd > cols || colEnd < 0) {
        return false;
    }
    if (rowEnd > rows || rowEnd < 0) {
        return false;
    }
    if(!x && !y){
        return false;
    }
    return true;
}
int main(void){
    int cases;
    bool first = true;
    string input;
    cin >> cases;
    getchar();
    getline(cin,input);
    for (int c = 0; c < cases; c++) {
        int rows, cols,words, position;
        char ch;
        cin >> rows >> cols;
        char grid[55][55];
        for (int r = 0; r < rows; r++) {
            for (int v = 0; v < cols; v++) {
                cin >> ch;
                grid[r][v] = tolower(ch);
                //cout << grid[r][v];
            }
            //cout << endl;
        }
        cin >> words;
        string wordStore[25];
        for (int w = 0; w < words; w++) {
            cin >> input;
            for (int i = 0; i < input.size(); i++) {
                input[i] = tolower(input[i]);
            }
            wordStore[w] = input;
            //cout << wordStore[w] << endl;
        }
        string curWord;
        if(!first){
            cout << endl;
        }
        first = false;
        for (int w = 0; w < words; w++) {
            curWord = wordStore[w];
            bool found = false;
            for (int r = 0; r < rows && !found; r++) {
                for (int v = 0; v < cols && !found; v++) {
                    for (int x = -1; x < 2 && !found; x++) {
                        for (int y = -1; y < 2 && !found; y++) {
                            if (possible(rows, cols, r, v, x, y, curWord.size())) {
                                //cout << r+1 << " " << v+1 << " " << x << " " << y << " "<< curWord << " is possible" << endl;
                                bool localFound = true;
                                position = 0;
                                while (position < curWord.size()) {
                                    if (grid[r + (x*position)][v + (y*position)] == curWord[position]) {
                                        position++;
                                    }else{
                                        localFound = false;
                                        break;
                                    }
                                }
                                if(localFound){
                                    cout  << r+1 << " "<< v+1 << endl;
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
            //cout << endl;
        }
        
    }
}
