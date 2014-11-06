//
//  led.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 31/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>

using namespace std;
int noBreaks[10] = {126, 48,109,121,51, 91,95,112,127,123};

bool check(int j, int level, int bulbVector, int* lineKeeper, int target){
    if(level == target){
        //cout << "Match found when i: " << bulbVector << " and start line is " << j << endl;
        return true;
    }
    bool works = false;
    for (int i = 0; i < 128; i++) {
        if((bulbVector&i) == i && lineKeeper[level] == (noBreaks[j]&i)){
            //cout << "Checking " << i << " on level " << level << " and start line "<< j<< endl;
            if(check(j-1, level+1, i, lineKeeper, target)){
                works = true;
                break;
            }
            if(works){
                break;
            }
        }
    }
    if(works){
        return true;
    }
    return false;
}

int main(void){
//    for (int i = 0; i < 10; i++) {
//        for (int j = 6;  j >=0 ; j--) {
//            if((noBreaks[i]&(1<<j)) == 0){
//                cout <<"N";
//            }else{
//                cout <<"Y";
//            }
//        }
//        cout << endl;
//    }
    int lines; cin >> lines;
    int lineKeeper[12];
    while(lines > 0){
        for (int i = 0; i < lines; i++) {
            int temp = 0;
            char read;
            for (int j = 6; j >=0 ; j--) {
                cin >> read;
                if (read == 'Y') {
                    temp += (1<<j);
                }
            }
            lineKeeper[i] = temp;
        }
        bool match = false;
//        for (int i = 0; i < lines; i++) {
//            cout << lineKeeper[i] << endl;
//        }
        for (int j = 9; j >= lines-1; j--) {
            bool found = check(j,0,127,lineKeeper, lines);
            if(found){
                match = true;
            }
        }
        if(!match){
            cout << "MIS";
        }
        cout << "MATCH" << endl;
        cin >> lines;
    }
    
}
