//
//  syndeyA.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 30/09/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct triangle {
    int sides[3];
    double grey;
    int occupied = -1;
};

bool customSort(triangle t1, triangle t2){
    return t1.grey < t2.grey;
}

bool fit(triangle t1, triangle t2){
    bool fit = false;
    for (int i = 0; i < 3; i++) {
        if(t1.occupied != i && t2.occupied != i && t1.sides[i] == t2.sides[i]){
            fit = true;
        }
    }
    return fit;
}

int main(void){
    int numTri;
    cin >> numTri;
    triangle triangles[100100];
    int topScore[100100];
    for(int t = 0; t < numTri; t++){
        cin >> triangles[t].sides[0] >> triangles[t].sides[1] >> triangles[t].sides[2] >> triangles[t].grey;
    }
    sort(triangles, triangles+numTri, customSort);
    topScore[0] =1;
    int overallMax = 1;
    for(int t = 1; t < numTri; t++){
        //do longest increasing subsequence
        int maxChain = 1;
        for(int i = t-1;  i >= 0; i--){
            if(fit(triangle[i], triangle[t]) && topScore[i] >= maxChain+1){
                maxChain = topScore[i]+1;
            }
        }
    }
    
    
}
