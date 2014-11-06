//
//  trainSwap.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 5/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int main(void){
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int length;
        cin >> length;
        int train[55];
        for (int l = 0; l < length; l++) {
            cin >> train[l];
        }
        bool ordered = false;
        int counter = 0;
        while (!ordered) {
            bool swappin = false;
            for (int l = 0; l < length - 1; l++) {
                if (train[l] > train[l+1]) {
                    swap(train[l], train[l+1]);
                    counter++;
                    swappin = true;
                    break;
                }
            }
            if(!swappin){
                ordered = true;
                cout << "Optimal train swapping takes " << counter << " swaps." << endl;
            }
        }
    }
    
}
