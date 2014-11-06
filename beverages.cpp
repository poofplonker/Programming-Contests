//
//  beverages.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 28/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi visited;
vi hasParent;
vi inDegree;
vvi adjOut;
vi startList;
vi top;
vi level;
map<string,int> drinkDict;
map<int,string> reverseDict;

void topSort(int numDrinks){
    for (int i = 0; i < numDrinks; i++) {
        if(hasParent[i] == 0){
            startList.push_back(i);
            level[i] = 0;
            cout << reverseDict[i]<< " has no parent" << endl;
        }
    }
    priority_queue<int> q;
    for (vi::iterator it = startList.begin(); it != startList.end(); it++) {
        q.push(*it);
        cout << "Enqueuing " << reverseDict[*it] << endl;
    }
    startList.clear();
    int currentLevel = 0;
    while (!startList.empty() || !q.empty()) {
        if(q.empty()){
            for (vi::iterator it = startList.begin(); it != startList.end(); it++) {
                if(level[*it] == currentLevel+1){
                    q.push(*it);
                    cout << "Enqueuing " << reverseDict[*it] << "level: " << level[*it]<< endl;
                }
                
            }
            startList.clear();
            currentLevel++;
        }
        int current = q.top();
        cout << "Popped: " << reverseDict[current] << endl;
        q.pop();
        if (visited[current] != 1) {
            visited[current] = 1;
            top.push_back(current);
            
            cout << "Adding " << reverseDict[current] << " to topsort" << endl;
            for (vi::iterator it = adjOut[current].begin(); it != adjOut[current].end(); it++) {
                inDegree[*it]--;
                if(inDegree[*it]== 0){
                    startList.push_back(*it);
                    level[*it] = level[current]+1;
                    
                }
            }
            //whyis beer t2?
        }
    }
    reverse(top.begin(), top.end());
}
int main (void){
    int numDrinks,numEdges;
    int counter = 1;
    while(cin >> numDrinks){
        top.clear();
        level.clear();
        level.resize(numDrinks,0);
        visited.clear();
        visited.resize(numDrinks,-1);
        adjOut.clear();
        adjOut.resize(numDrinks);
        hasParent.clear();
        hasParent.resize(numDrinks,0);
        inDegree.clear();
        inDegree.resize(numDrinks,0);
        startList.clear();
        for (int i = 0; i < numDrinks; i++) {
            string input;
            cin >> input;
            drinkDict[input] = i;
            reverseDict[i] = input;
        }
        getchar();
        cin >> numEdges;
        string input1, input2;
        for (int i = 0; i < numEdges; i++) {
            cin >> input1 >> input2;
            adjOut[drinkDict[input2]].push_back(drinkDict[input1]);
            inDegree[drinkDict[input1]]++;
            hasParent[drinkDict[input1]] = 1;
        }
        if (counter > 1) {
            cout << endl;
        }
        
        getchar();
        topSort(numDrinks);
        cout << "Case #" << counter << ": Dilbert should drink beverages in this order: ";
        for (vi::iterator it = top.begin(); it != top.end(); it++) {
            cout << " " <<reverseDict[*it];
        }
        counter++;
        cout << "."<< endl;
    }
}
