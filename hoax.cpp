
//
//  hoaxes.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 11/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <cstdio>
using namespace std;

int main(void){
    int cases;
    cin >> cases;
    getchar();
    while (cases != 0) {
        //cout << "In main loop " << endl;
        multiset<int> urn;
        string input;
        long counter = 0;
        for (int c = 0 ; c < cases; c++) {

            getline(cin,input);
            stringstream stream;
            
            stream << input;
            int r,temp; // receipts for that day
            stream >> r;
            
            for (int i = 0; i < r; i++) {
                stream >> temp;
                urn.insert(temp);
            }
            multiset<int>::iterator it;
            it = urn.begin();
            int lowest = *(it);
            urn.erase(it);
            
            it = urn.end();
            int highest = *(--it);
            urn.erase(it);
            //cout << "In next case after this" << endl;
            //cout << "Day " << c << ": " << highest << " " << lowest << endl;
            counter += highest - lowest;
        }
        cout << counter << endl;
        cin >> cases; getchar();
    }
    return 0;
}
