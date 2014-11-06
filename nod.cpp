//
//  nod.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 27/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nod(int thing){
    int counter = 0;
    for (int i = 1; i <= thing; i++) {
        if(thing%i == 0){
            counter++;
        }
    }
    return counter;
}
int main(void){
    vector<int> array;
    array.resize(100000);
    array[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        int nodi = nod(i-1);
        //cout << nodi << endl;
        array[i] = array[i-1] + nodi;
    }
//    for(vector<int>::iterator it = array.begin(); it != array.end() ; it++){
//        cout << *it << " ";
//    }
    cout << endl;
    int queries;
    cin >> queries;
    for (int i = 0 ; i < queries ; i++) {
        int lower, upper;
        cin >> lower >> upper;
        cout << lower << " " << upper << endl;
        vector<int>::iterator lowResult = lower_bound(array.begin(), array.end(), lower);
        vector<int>::iterator upResult = upper_bound(lowResult, array.end(), upper-1);
        cout << *lowResult << " " << *upResult << endl;
        cout << upResult - lowResult << endl;
    }
}
