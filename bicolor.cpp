//
//  bicolor.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 29/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define red 0
#define blue 1
#define uncoloured -1

using namespace std;
typedef vector<int> vi;
typedef vector <vi> vvi;

vvi adjList;
vi colourList;

int main(void){
    int nodes, edges, node1, node2;
    cin >> nodes;
    while (nodes != 0) {
        cin >> edges;
        adjList.clear();
        adjList.resize(nodes);
        colourList.clear();
        colourList.resize(nodes, uncoloured);
        for (int i = 0; i < edges; i++) {
            cin >> node1 >> node2;
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        bool colourable = true;
        queue<int> q;
        q.push(0);
        colourList[0] = blue;
        int currentColour = blue;
        int currentNode;
        while (!q.empty() && colourable) {
            currentNode = q.front();
            //cout << "Current Node: " << currentNode << endl;
            currentColour = colourList[currentNode];
            //cout << "Its colour is " << colourList[currentNode] << endl;
            q.pop();
            for (vi::iterator it = adjList[currentNode].begin(); it != adjList[currentNode].end(); it++) {
                if (colourList[*it] == uncoloured) {
                    //cout << "Colouring: " << *it  << " "<< 1 - currentColour<<  endl;
                    colourList[*it] = 1 - currentColour;
                    q.push(*it);
                }else if(colourList[*it] == currentColour){
                    //cout << *it <<" and " << currentNode << " have edge and are same colour." << endl;
                    colourable = false;
                    break;
                }
            }
        }
        if(!colourable){
            cout << "NOT ";
        }
        cout << "BICOLORABLE." << endl;
        cin >> nodes;
    }
}
