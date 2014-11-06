//
//  brokenPed.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 22/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int count_ones(int i){
    int counter;
    while (i != 0) {
        if (i % 2 == 1) {
            counter++;
        }
        i >>= 1;
    }
    return counter;
}

int main(void){
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int P,L;
        int symbolArray[100];
        cin >> P >> L;
        for (int p = 0; p < L; p++) {
            int symbol = 0,temp = 0;
            for(int i = 0; i < P; i++){
                cin >> temp;
                symbol += (temp << (P-1-i));
            }
            symbolArray[p] = symbol;
        }
        int tempSymbolArray[100];
        int minSymbols = P;
        for (int i = 0; i < (1 << P); i++) {
            for (int j = 0; j < L; j++) {
                tempSymbolArray[j] = symbolArray[j]&i;
            }
            sort(tempSymbolArray, tempSymbolArray+L);
            bool unique = true;
            for(int k = 0; k < L-1;k++){
                if(tempSymbolArray[k] == tempSymbolArray[k+1]){
                    unique = false;
                    break;
                }
            }
            if(unique){
                int ones = count_ones(i);
                if(ones < minSymbols){
                    minSymbols = ones;
                }
            }
        }
        cout <<minSymbols << endl;
    }
}
