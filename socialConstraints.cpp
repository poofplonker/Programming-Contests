//
//  socialConstraints.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 22/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
    int num_teenagers, num_constraints;
    int teenPerm[10], constraints[25][3];
    cin >> num_teenagers >> num_constraints;
    while (num_teenagers != 0 || num_constraints != 0) {
        
        for (int i  = 0; i < num_constraints; i++) {
            cin >> constraints[i][0] >> constraints[i][1] >> constraints[i][2];
        }
        for (int i = 0; i < num_teenagers; i++) {
            teenPerm[i] = i;
        }
        int counter = 0;
        long distance;
        do{
            bool failed = false;
            for (int i = 0; i < num_constraints; i++) {
                if(constraints[i][2] > 0){
                    distance = abs(find(teenPerm, teenPerm+num_teenagers, constraints[i][1]) - find(teenPerm,teenPerm+ num_teenagers,constraints[i][0]));
                    if(distance > constraints[i][2]){
                        failed = true;
                        break;
                    }
                }else{
                    distance = abs(find(teenPerm, teenPerm+num_teenagers, constraints[i][1]) - find(teenPerm,teenPerm+ num_teenagers,constraints[i][0]));
                    if(distance < -1*constraints[i][2]){
                        failed = true;
                        break;
                    }
                }
            }
            if(!failed){
                counter++;
            }
        }
        while (next_permutation(teenPerm, teenPerm+num_teenagers));
        cout << counter << endl;
        cin >> num_teenagers >> num_constraints;
    }
}
