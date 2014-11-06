//
//  magicNumbers.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 21/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool no_repeat(string s1){
    vector<int> repeats;
    repeats.resize(10,0);
    for (int i = 0; i < s1.length(); i++) {
        repeats[s1[i]- '0']++;
        if(repeats[s1[i] - '0'] > 1){
            return false;
        }
    }
    return true;
}

int main(void){
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        long long N;
        cin >> N;
        bool done = false;
        int s2 = 1;
        if(c){
            cout << endl;
        }
        while (!done) {
            stringstream io("");
            string string1,string2;
            long long s1 = s2*N;
            io << s1 << " "<< s2;
            
            //cout << N << " " << s2 << endl;
            io >> string1 >> string2;
            //cout << string1 << " and " <<string2 << endl;
            //cout << no_repeat(string1) << " "<< no_repeat(string2)<< endl;
            if(no_repeat(string1) && no_repeat(string2)){
                cout << string1 << " / " << string2 << " = " << N << endl;
            }
            s2++;
            if (string1.length() > 10) {
                //cout << "In break case" << endl;
                done = true;
            }
        }
    }
}