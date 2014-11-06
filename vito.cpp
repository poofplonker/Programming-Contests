//
//  vito.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 24/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
using namespace std;
int main(void){
    int cases;
    cin >> cases;
    getchar();
    for (int c = 0; c < cases; c++) {
        int relDist[600], rel,median, sum = 0;
        string input;
        getline(cin, input);
        stringstream ss;
        ss << input;
        ss >> rel;
        for (int r = 0; r < rel; r++) {
            ss >> relDist[r];
        }
        sort(relDist, relDist+rel);
        median = rel/2;
        for (int r = 0; r < rel; r++) {
            sum += abs(relDist[r]- relDist[median]);
        }
        cout << sum << endl;
        
    }
    
}
