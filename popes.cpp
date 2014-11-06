//
//  popes.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 27/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main(void){
    int years, popeStart = 0;
    vi popesAfter;
    popesAfter.resize(1000020,0);
    int popes[1000000];
    while (cin >> years) {
        fill(popesAfter.begin(),popesAfter.end(),0);
        int num_popes;
        cin >> num_popes;
        int max = 0;
        int startPos = 0;
        for (int i = 0; i < num_popes; i++) {
            cin >> popes[i];
            popeStart = popes[i];
            for (int j = popeStart; j > 0 && j > popeStart - years; j--) {
                popesAfter[j]++;
                if(popesAfter[j] > max){
                    max = popesAfter[j];
                    startPos = j;
                }
            }
        }
//        for(int i = 0; i < 32; i++){
//            cout << popesAfter[i] << " ";
//        }
        cout << startPos+years << endl;
        vi vpopes(popes, popes+num_popes);
        int firstPope = *(upper_bound(popes, popes+num_popes, startPos-1));
        vi::iterator lastPope = upper_bound(vpopes.begin(),vpopes.end(), startPos+years-1);
        int result;
        if(*lastPope == startPos+years)
        {
            result = *lastPope;}
        else{
            result = *(lastPope-1);
        }//cout << "Max: " << max  << endl;
        cout << max << " " << firstPope << " "<< result<<  endl;
    }
}
