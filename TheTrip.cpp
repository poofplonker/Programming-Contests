//
//  TheTrip.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 3/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

bool comp (int i,int j) { return (i>j); }

int main(void){
    int students;
    while(cin >> students){
        if(!students){
            return 0;
        }
        double input;
        char dot;
        int first, second;
        
        int* costArray = new int[students];
        int total = 0;
        for(int i = 0; i < students; i++){
            cin >> first;
            cin >> dot;
            cin >> second;
            //cout << first << endl << second << endl;
            costArray[i] = first*100 + second;
            total += costArray[i];
        }
        
        int average = total/students;
        int leftover = total%students;
        
        //cout << "total: " << total << endl;
        //cout << "average: " << average << endl;
        //cout << "leftover: " << leftover << endl;
        vector<int> sortedCost(costArray, costArray+students);
        sort(sortedCost.begin(),sortedCost.end(), comp);
        int transfer = 0;
        int i = 0;
        while(sortedCost[i] > average){
            if(leftover > 0){
                transfer += (sortedCost[i] - average - 1);
                leftover--;
            }else{
                transfer += (sortedCost[i] - average);
            }
            i++;
        }

        cout << setprecision(2) << "$" << transfer/100 << "." << setfill('0') << setw(2) << transfer%100 << endl;
                        
        delete[] costArray;
    }
}
