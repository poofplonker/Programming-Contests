//
//  openSource.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 11/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool custComp(pair<string, int> first, pair<string, int> second){
    if (first.second > second.second) {
        return true;
    }else if(first.second == second.second){
        if (first.first <= second.first) {
            return true;
        }
    }
    return false;

}

int main(void){
    string input;
    getline(cin, input);
    while (input != "0") {
        string currentProj;
        set<string> studentList;
        set<string> removed;
        map<string, string> studToProj;
        map<string, int> projCount;
        
        while (input != "1") {
            if(isupper(input[0])){
                //cout << "Cap seen, adding to stud toProj" << endl;
                currentProj = input;
                projCount[input] = 0;
            }else{
                //cout << "no caps, student" << endl;
                if (studentList.find(input) == studentList.end()) {
                    //cout << "student not yet in list"<< endl;
                    studentList.insert(input);
                    studToProj[input] = currentProj;
                    projCount[currentProj]++;
                }else if(studToProj[input] != currentProj && removed.find(input) == removed.end()){
                    //cout << "student already registered"<< endl;
                    studToProj.erase(studToProj[input]);
                    removed.insert(input);
                    if (projCount[studToProj[input]] != 0){
                        projCount[studToProj[input]]--;
                    }

                }
            }
            getline(cin, input);
        }
        vector<pair<string,int> > temp;
        for(map<string, int>::iterator it = projCount.begin(); it != projCount.end(); it++){
            pair< string,int> temp2(it->first,it->second);
            temp.push_back(temp2);
            
        }
        sort(temp.begin(), temp.end(),custComp);
        for (vector<pair<string,int> >::iterator it = temp.begin(); it!= temp.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
        getline(cin, input);
    }
}
