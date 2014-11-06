//
//  hartal.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 7/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
using namespace std;

int main(void){
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int num_parties, num_days;
        int parties[120];
        int days[4000];
        for (int d = 0; d < 4000; d++) {
            days[d]= 0;
            if(d < 120){
                parties[d] = 0;
            }
        }
        cin >> num_days >> num_parties;
        for (int p= 0; p < num_parties; p++) {
            cin >> parties[p];
        }
        int hartals = 0;
        for (int p = 0; p < num_parties; p++) {
            for (int d = 0; d < num_days; d++) {
                if((d%7 == 6 || d%7 == 5)){
                    days[d] = 1;
                }
                if ((d%parties[p] == (parties[p]-1)) && !days[d]) {
                    hartals++;
                    days[d] = 1;
                }
            }
        }
        cout << hartals << endl;
        
    }
}
