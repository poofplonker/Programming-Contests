//
//  continent.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 28/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int floodFill(int x, int y,  char c1, char c2);
char map[22][22];
int width, height, resideX, resideY;
int col[4] = {-1,0,0,1};
int row[4] = {0,-1,1,0};
int main(void){
    while(cin >> height >> width){
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cin >> map[y][x];
            }
        }
        cin >> resideY >> resideX;
        char land = map[resideY][resideX];
       // cout << "Land: " << land << endl;
        int maxValue = 0;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if(map[y][x] == land){
                    //cout << "Floodfill in main loop"<< endl;
                    //cout << "Floodfill: " << y << " " << x << endl;
                    int temp = floodFill(x, y, land, '6');
                    if(temp > maxValue){
                        maxValue = temp;
                    }
                }
            }
        }
        cout << maxValue << endl;
    }
    
}

int floodFill(int x, int y,  char c1, char c2){
    //if out of bounds
    if(x < 0){
        x += width;
    }else if(x >= width){
        x -= width;
    }
    if(x == resideX && y == resideY){
        //cout << "Living at: " << resideY << " " << resideX << endl;
        return -1;
    }

    if(y < 0 || y >= height){
        return 0;
    }if(map[y][x] != c1){
        return 0;
    }
    int ans = 1;
    map[y][x] = c2;
    bool failed = false;
    for (int i = 0; i < 4; i++) {
        //cout << "Floodfill: " << y+row[i] << " " << x+col[i] << endl;
        int temp = floodFill(x+col[i], y+row[i], c1, c2);
        //cout << "Result: " << temp << endl;
        if(temp == -1){
            failed = true;;
        }
        ans += temp;
    }
    if(failed){
        return -1;
    }
    return ans;
}
