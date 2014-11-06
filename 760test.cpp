//
//  760test.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 21/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>

using namespace std;
int main(void){
    map<int, int> dict;
    map<int,int> totalDict;
    int item;
    int lineCounter = 0;
    int itemCounter= 0;
    int twent7 = 0;
    int thrit7 = 0;
    int max = 0;
    string input;
    stringstream store;
    while (getline(cin, input)) {
        stringstream io;
        io << input;
        int minicounter = 0;
        bool thirty_two = false;
        bool seven = false;
        bool twenty_eight = false;
        while (io >> item) {
            if(item == 7){
                seven = true;
            }
            if(item == 32){
                thirty_two = true;
            }
            if(item == 28){
                twenty_eight = true;
            }
            if(seven && thirty_two){
                thrit7++;
                seven = false;
            }
            if(seven && twenty_eight){
                twent7++;
                seven = false;
            }
            minicounter++;
            if (totalDict.find(item) == totalDict.end()) {
                itemCounter++;
                totalDict[item] = 1;
                if(item > max){
                    max = item;
                }
            }else{
                totalDict[item]++;
            }
            
        }
        if(minicounter !=1){
            dict[lineCounter] = 1;
        }
        lineCounter++;
        store << input << endl;
    }
//    cout << "There are " << itemCounter << " single lines" << endl;
//    cout << "The biggest numerical value is " << max <<endl;
//    cout << "Here comes our dictionary" << endl << endl;
    cout << "28: " << totalDict[28] << endl;
    cout << "32: " << totalDict[32] << endl;
    cout << "7: " << totalDict[7] << endl;
    cout << "11: " << totalDict[11] << endl;
    cout << "6: " << totalDict[6] << endl;
    cout << " 32 7: " << thrit7 << endl;
    cout << "28 7: " << twent7 << endl;
    cout << "218: " << totalDict[218] << endl;
    cout << "4832: " << totalDict[4832] << endl;
    cout << "71: " << totalDict[71] << endl;
    
   // vector<pair<int, int> > items;
    
    
//    for (map<int,int>::iterator it = dict.begin();it !=  dict.end(); it++) {
//        pair<int, int> temp(it->second, it->first);
//        items.push_back(temp);
//    }
//    sort(items.begin(), items.end());
//    for (vector<pair<int, int> >::iterator it = items.begin(); it != items.end(); it++) {
//        if(totalDict[(*it).second] >= 10000){
//            cout << (*it).second << ": " << totalDict[(*it).second] <<endl;
//        }
//    }
//    lineCounter = 0;
//    while (getline(store, input)) {
//        stringstream io;
//        //cout << input << endl;
//        io << input;
//        int value;
//        bool oneValue = false;
//        while (io >> value) {
//            //cout << "Number of " << value <<": "<<dict[value] << endl;
//            if(dict[lineCounter] == 1 && totalDict[value] < 50000 && totalDict[value] > 500){
//                oneValue = true;
//                cout << value << " ";
//            }
//        }
//        lineCounter++;
//        if(oneValue){
//            cout << endl;
//        }
//    }
}
