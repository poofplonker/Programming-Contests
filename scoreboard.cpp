//
//  scoreboard.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 14/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

class Contestant{
    public:
        int number;
        int num_solved;
        int penalties;
        int solved[10];
        int accruedPen[10];
        bool submitted;
    Contestant(){
        number = 0;
        num_solved = 0;
        penalties = 0;
        submitted = false;
        for (int i = 0; i < 10; i++) {
            solved[i] = 0;
            accruedPen[i] = 0;
        }
    }
    
};
bool ValueCmp(const Contestant x,const Contestant y){
    //cout << "Comparing " << x.number << " and " << y.number << endl;
    if(x.num_solved > y.num_solved){
        //cout << x.number << " has more problems solved than " << y.number << endl;
        return true;
        
    }
    if (x.num_solved == y.num_solved) {
        if (x.penalties < y.penalties){
            //cout << x.number << " has higher penalty than " << y.number << endl;
            return true;
        }
        if(x.penalties == y.penalties){
            //cout << x.number << " has same solved and penalty as " << y.number << endl;
            if(x.submitted && y.submitted){
                return x.number < y.number;
            }
            else if(x.submitted){
                return true;
            }
        }
        //cout << x.number << " has lower penalty than " << y.number << endl;
    }
    //cout << x.number << " has less problems solved than " << y.number << endl;
    return false;
}

int main(void){
    int cases;
    bool first = true;
    cin >> cases;
    getchar();
    string input;
    getline(cin, input);
    for (int c = 0; c < cases; c++) {
        Contestant teams[120];
        for (int i = 1; i < 120; i++) {
            teams[i].number = i;
        }
        //cout << "Contestants initialised" << endl;
        
        int cont, prob, time;
        char judge;
        while (getline(cin, input)){
            stringstream s;
            //cout << "Reading: " << input << endl;
            if(input == ""){
                break;
            }
            s << input;
            s >> cont >> prob  >> time >> judge >> judge;
            //cout << "Taken " << cont << " " << prob << " " << time << " " <<judge << endl;
            if (!teams[cont].solved[prob]) {
                switch (judge) {
                    case 'C':
                        teams[cont].num_solved++;
                        teams[cont].solved[prob] = 1;
                        teams[cont].penalties += time;
                        teams[cont].penalties += teams[cont].accruedPen[prob];
                        teams[cont].submitted = true;
                        break;
                    case 'I':
                        teams[cont].accruedPen[prob]+=20;
                        teams[cont].submitted = true;
                        break;
                    default:
                        teams[cont].submitted = true;
                        break;
                }
            }
            
        }
        vector<Contestant> vec (teams, teams+120);
        sort(vec.begin(), vec.end(),ValueCmp);
        if(!first){
            cout << endl;
        }
        first = false;
        for (vector<Contestant>::iterator it = vec.begin(); it != vec.end() && (*it).submitted; it++) {
            cout << it->number << " " << it->num_solved << " " << it->penalties << endl;
        }
        
        
    }
    return 0;
}

