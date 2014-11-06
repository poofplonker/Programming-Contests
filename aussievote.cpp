//
//  aussievote.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 4/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;
int main(void){
    int cases;
    string input;
    cin >> cases;
    getchar();
    getline(cin, input);
    bool first = true;
    for (int i = 0; i < cases; i++) {
        //cout << "On " << i << "th case." << endl;
        int num_cand;
        int num_voter = 0;
        int voter[1000][25];
        cin >> num_cand;
        getchar();
        string candidates[25];
        for (int j = 0; j < num_cand; j++) {
            getline(cin, input);
            candidates[j] = input;
            //cout << "Candidate " << j << " :" << input << endl;
        }
        getline(cin, input);
        while (!input.empty()) {
            stringstream o;
            o << input;
            for (int j = 0; j < num_cand; j++) {
                o >> voter[num_voter][j];
            }

            num_voter++;
            //cout << input << endl;
            //cout << "Voters counted: " << num_voter<< endl;
            if(cin.eof()){
                break;
            }
            getline(cin, input);
        }
        bool isWinner = false;
        int winner = -1;
        int num_elim = 0;
        bool eliminated[25];
        int votecount[25];
        for (int j = 0; j< num_cand; j++) {
            eliminated[j] = false;
        }
        if(!first){
            cout << endl;
        }
        first = false;
        for (int j = 0; j < num_cand && !isWinner; j++) {
            for (int k = 0; k < num_cand; k++) {
                votecount[k] = 0;
            }
            for (int k = 0; k < num_voter; k++) {
                int l = 0;
                while (eliminated[voter[k][l]-1]) {
                    l++;
                }
                votecount[voter[k][l]-1]++;
            }
            
            int smallest = num_voter;
            for (int k = 0; k < num_cand; k++) {
                //cout << candidates[k] << " has " << votecount[k] << " votes." << endl;
                if (votecount[k] >= (num_voter/2 + 1)) {
                    winner = k;
                    isWinner = true;
                    cout << candidates[k] << endl;
                }
                if(votecount[k] < smallest && !eliminated[k]){
                    smallest = votecount[k];
                }

            }
            for (int k = 0; k < num_cand; k++) {
                if(votecount[k] == smallest){
                    eliminated[k] = true;
                    num_elim++;
                }
            }
            if(num_elim == num_cand && !isWinner){
                for (int k = 0; k < num_cand; k++) {
                    if (votecount[k]) {
                        cout << candidates[k] << endl;
                    }
                }
                isWinner = true;
            }

        }
        for(int j = 0; j < 1000; j++){
            for (int k = 0; k < 25; k++) {
                voter[j][k] = 0;
            }
        }
 
        
    }

}
