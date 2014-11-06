//
//  FileFragmentation.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 23/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customSort(string s1, string s2){
    if (s1.size() < s2.size()) {
        return true;
    }else if (s1.size() == s2.size()){
        if(s1.compare(s2) <0 ){
            return true;
        }
    }
    return false;
}

int main(void){
    int cases;
    cin >> cases;
    getchar();
    string input;
    getline(cin,input);
    
    for (int c = 0; c < cases; c++) {
        vector<string> fragments;
        int f = 0;
        getline(cin, input);
        while (input != "") {
            //cout << input << endl;
            fragments.push_back(input);
            f++;
            if (cin.eof()) {
                break;
            }
            getline(cin,input);
        }
        //cout << "f: " << f << endl;
        sort(fragments.begin(), fragments.end(), customSort);
        /*for (int i =0; i < f; i++) {
            cout << fragments[i] << endl;
        }*/
        if(c != 0){
            cout << endl;
        }
        bool solved = false;
        int matcher = f-1;
        int z = 0;
        while(!solved){
            vector<string> workingSet;
            for (int i = 0; i < f; i++) {
                workingSet.push_back(fragments[i]);
            }
            string full;
            if(z){
                full = workingSet[0] + workingSet[matcher];
            }else{
                full = workingSet[matcher] + workingSet[0];
            }
            workingSet.erase(workingSet.begin()+matcher);
            workingSet.erase(workingSet.begin());
            //cout << "Full string: " << full << endl;
            /*for (int i =0; i < workingSet.size(); i++) {
                cout << workingSet[i] << endl;
            }*/
            while (workingSet.size() > 0) {
                string desired;
                if(full.find(workingSet[0]) == 0){
                    desired = full.substr(workingSet[0].size());
                }if (full.rfind(workingSet[0]) + workingSet[0].size() == full.size()) {
                    desired = full.substr(0,full.rfind(workingSet[0]));
                }
                //cout << "desired: " << desired << endl;
                if(!binary_search(workingSet.begin(), workingSet.end(), desired, customSort)){
                    if(z){
                        z = 0;
                        matcher--;
                    }else{
                        z = 1;
                    }
                    break;
                }
                vector<string>::iterator it = find( workingSet.begin(), workingSet.end(), desired);
                
                workingSet.erase(it);
                //cout << "Second erase is fine " << endl;
                workingSet.erase(workingSet.begin());
                //cout << "First erase is fine " << endl;
                //cout << "Iterator pointing at: " << *it << endl;
                
                
                if(workingSet.size() == 0){
                    solved = true;
                    
                }
                
            }
            if (solved || workingSet.size() == 0) {
                solved = true;
                cout << full <<endl;
            }
        }
        
        
        
    }
}
