//
//  minotaur.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 27/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <sstream>
#include <string>

#define VERTEX -1
#define EDGES 1
#define DONE 0
#define CANDLE 1

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adjList;
vi candled;

void dfs(int minotaurVert, int theseusVert, int counter, int k){
    bool escape = true;
    while (escape) {
        if (counter == k) {
            candled[theseusVert] = CANDLE;
            counter = 0;
            cout << char(theseusVert + 'A') << " ";
        }
        escape = false;
        for (vi::iterator it = adjList[minotaurVert].begin(); it != adjList[minotaurVert].end(); it++) {
            if (candled[*it] == 0 && *it != theseusVert) {
                escape = true;
                theseusVert = minotaurVert;
                minotaurVert = *it;
                counter++;
                break;
            }
        }
        if(!escape){
            cout << "/" << char(minotaurVert + 'A') << endl;
        }
    }
}

int main(void){
    string input;
    while (getline(cin, input)){
        adjList.clear();
        adjList.resize(1000);
        candled.clear();
        candled.resize(1000,0);
        int state = VERTEX;
        int currentVertex = 0;
        int minotaurVert = 0;
        int theseusVert = 0;
        int k = 0;
        stringstream io;
        char temp;
        string left;
        for (int i = 0; i < input.length(); i++) {
            switch(input[i]){
                case ':':
                    state = EDGES;
                    break;
                case ';':
                    state = VERTEX;
                    break;
                case '#':
                    return 0;
                case '.':
                    left = input.substr(i+1);
                    io << left;
                    io >> temp;
                    minotaurVert = temp - 'A';
                    io >> temp;
                    theseusVert = temp - 'A';
                    io >> k;
                    state = DONE;
                    break;
                default:
                    if (state == EDGES) {
                        adjList[currentVertex].push_back(input[i]-'A');
                    }else if(state == VERTEX){
                        currentVertex = input[i] - 'A';
                    }
                    break;
            }
        }
        int counter = 0;
        dfs(minotaurVert, theseusVert, counter, k);
    }
}