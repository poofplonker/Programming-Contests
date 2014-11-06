//
//  blockVoting.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 21/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int cases;
    cin >> cases;
    int parties, members[25], power[25];
    for (int c = 0; c < cases; c++) {
        cin >> parties;
        int majority = 0;
        for (int p = 0; p < parties; p++) {
            cin >> members[p];
            majority += members[p];
            power[p] = 0;
        }
        majority = majority/2 + 1;
        //cout << "Majority required: " << majority << endl;
        //cout << "Parties "<< parties<< endl;
        for (int coal = 0; coal < (1 << parties); coal++) {

            int coalScore = 0;
            vector<int> partyInCoal;
            for (int i = 0; i < parties; i++) {
                if (((1 << i)&coal) > 0) {
                    coalScore += members[i];
                    //cout << "Member " << i+1 << " in coalition "<< coal << endl;
                }
            }
            //cout << "Coalition score " << coalScore << endl;
            if(coalScore < majority){
                for (int i = 0; i < parties; i++) {
                    if(((1 << i)&coal) == 0 && coalScore+ members[i] >= majority){
                        power[i]++;
                    }
                    
                    //cout << "Adding more power to " << *it << endl;
                }
            }
            
        }
        for (int i = 0; i < parties; i++) {
            cout << "party " << i+1 << " has power index " << power[i] << endl;
        }
        cout << endl;
    }
    
}
