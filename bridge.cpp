//
//  bridge.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 25/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int main(void){
    string input;
    int cases;
    cin >> cases;
    getchar();
    getline(cin, input);
    for ( int c = 0; c < cases; c++){
        int num_peeps;
        int peeps[1100];
        vector<int> here;
        priority_queue<int, vector<int>, greater<int> > there;
        cin >> num_peeps;
        for (int p = 0; p < num_peeps ; p++) {
            cin >> peeps[p];
            here.push_back(peeps[p]);
        }
        sort(here.begin(), here.end());
        int score = 0;
        int runner1, runner2, fattie1, fattie2;
        stringstream output;
        if(c != 0){
            cout << endl;
        }
        while (here.size() > 2) {
            //select the two quickest runners on the here side;
            runner1 = here[0];
            runner2 = here[1];
            fattie1 = here[here.size() - 1];
            fattie2 = here[here.size() - 2];
            if (runner1 + fattie2 >= 2*runner2) {
                
                here.erase(here.begin());
                here.erase(here.begin());
                
                //run them across the bridge;
                score += runner2;
                output << runner1 << " " << runner2 << endl;
                
                //run the fastest back;
                score += runner1;
                output << runner1 << endl;
                here.insert(here.begin(), runner1);
                
                //now run the two slowest to the other side
                
                here.pop_back();
                here.pop_back();
                score+= max(fattie1,fattie2);
                output << fattie2 << " " << fattie1 << endl;
                //run the baton back if there is someone to run it to
                if (here.size()) {
                    score += runner2;
                    output << runner2 << endl;
                    here.insert(here.begin()+1, runner2);
                }
            }
            else{
                here.erase(here.begin());
                score += fattie2 + fattie1 + runner1;
                output << runner1 << " " << fattie2 << endl << runner1 << endl << runner1 << " " << fattie1 << endl;
                here.pop_back();
                here.pop_back();
                if (here.size()) {
                    score += runner1;
                    output << runner1 << endl;
                    here.insert(here.begin(), runner1);
                }
            }
            
            
        }
        if(here.size() == 2){
            score += max( here[0], here[1]);
            output << here[0] << " " << here[1] << endl;
        }
        if(here.size() == 1){
            score += here[0];
            output << here[0] << " " << endl;
        }
        string thing;
        cout << score << endl;
        while (getline(output, thing)) {
            //if(thing != ""){
                cout << thing << endl;
            //}
        }
        
        
        
    }
}
