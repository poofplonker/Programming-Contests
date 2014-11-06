//
//  jolly.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 4/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;
int main(void){
    string input;
    while (getline(cin,input)) {
        unordered_map<int,bool> map;
        stringstream s;
        s << input;
        int previous, next, num_nums;
        s >> num_nums;
        s >> previous;
        //cout << "Reading " << previous << endl;
        int num_matches = 0;
        map[0] = true;
        for (int i = 1; i < num_nums; i++) {
            s >> next;
            //cout << "Reading " << next << endl;
            //cout << "Difference: " << abs(next - previous) << endl;
            if (!map[abs(next - previous)]) {
                num_matches++;
                //cout << "New matchup." << endl;
                map[abs(next - previous)] = true;
            }
            previous = next;
        }
        bool jolly = true;
        for (int i = 1; i < num_nums; i++) {
            if (!map[i]) {
                jolly = false;
            }
        }
        if(jolly){
            cout << "Jolly" << endl;
        }else{
            cout << "Not jolly" << endl;
        }
    }
}
