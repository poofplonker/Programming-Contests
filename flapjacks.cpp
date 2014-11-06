//
//  flapjacks.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 24/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main(void){
    string input;
    do{
        getline(cin, input);
        if (input == "") {
            return 0;
        }
        cout << input << endl;
        int cakes[40], sortedCakes[40];
        stringstream ss;
        ss << input;
        int cake, c = 0;
        while (ss >> cake) {
            sortedCakes[c] = cake;
            cakes[c++] = cake;
        }
        sort(sortedCakes,sortedCakes+c);
        int sortedUntil = c;
        int *nextBigLoc = 0;
        bool sorted = false;
        //cout << "c: "<< c << endl;
        while(!sorted){
            if (sortedUntil == 0) {
                sorted = true;
                cout << 0 << endl;
                break;
            }
            if (sortedCakes[sortedUntil-1] == cakes[sortedUntil-1]) {
                sortedUntil--;
            }else{
                nextBigLoc = find(cakes, cakes+sortedUntil , sortedCakes[sortedUntil-1]);
                if(nextBigLoc-cakes != 0){
                    cout << c-(nextBigLoc-cakes) << " ";
                    reverse(cakes, nextBigLoc+1);
                }
                cout << c - sortedUntil+1 << " ";
                reverse(cakes, cakes+sortedUntil);
                sortedUntil--;
            }

        }
        
    }while (!cin.eof());
    
    

}
