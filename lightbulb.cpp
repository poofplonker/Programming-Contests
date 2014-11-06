//
//  lightbulb.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 2/09/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;
int bulbArray[12];
int changedArray[12];



void println(int i){
    for (int j = 9; j >= 0; j--) {
        if((changedArray[i] >> j)%2 == 1){
            cout << "O";
        }else{
            cout << "#";
        }
    }
    cout << endl;
}
void printBlock(){
    for (int i = 0; i < 10; i++) {
        println(i);
    }
    cout << endl;
}

int main(void){
    string name;
    while (true) {
        cin >> name;
        if (name == "end") {
            return 0;
        }
        char temp;
        for (int i = 0 ; i < 10; i++) {
            int row = 0;
            for (int j = 9; j >= 0; j--) {
                cin >> temp;
                if(temp == 'O'){
                    row += (1<<j);
                }
            }
            bulbArray[i] = row;
        }
        int minCounter = 200;
        for (int i = 0; i < (1<<10); i++) {
            //process first row
            int counter = 0;
            for (int j = 0; j < 10; j++) {
                changedArray[j] = bulbArray[j];
            }
            for (int k = 0; k < 10; k++) {
                if((i>>k)%2 == 1){
                    for (int l = k-1; l < k+2; l++) {
                        if(l >= 0 && l < 10 && (changedArray[0]>> l)%2 ==1){
                            changedArray[0] -= (1 << l);
                        }else if(l >= 0 && l < 10){
                            changedArray[0] += (1 << l);
                        }
                    }
                    if((changedArray[1]>> k)%2 ==1){
                        changedArray[1] -= (1 << k);
                    }else{
                        changedArray[1] += (1 << k);
                    }
                    counter++;
//                    if (i == 891) {
//                        cout << "j,k: " << 0 << " "<<  k << endl;
//                        printBlock();
//                    }
                }
            }
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 10; k++) {
                    if((changedArray[j] >> k)%2 == 1){
                        changedArray[j] -= (1<<k);
                        for (int l = k-1; l < k+2; l++) {
                            if(l >= 0 && l < 10 && (changedArray[j+1]>> l)%2 ==1){
                                changedArray[j+1] -= (1 << l);
                            }else if(l >= 0 && l < 10){
                                changedArray[j+1] += (1 << l);
                            }
                        }
                        if(j+2 < 10 && (changedArray[j+2]>> k)%2 ==1){
                            changedArray[j+2] -= (1 << k);
                        }else if(j+2 < 10){
                            changedArray[j+2] += (1 << k);
                        }
                        counter++;
//                        if (i == 891) {
//                            cout << "j,k: " << j+1 << " " << k << endl;
//                            printBlock();
//                        }
                    }
                }
            }
            //println(9);
            if(changedArray[9] == 0 && counter < minCounter){
                minCounter = counter;
                //cout << i << endl;
            }
        }
        if(minCounter > 100){
            minCounter = -1;
        }
        cout << name << " " << minCounter << endl;
    }
}
