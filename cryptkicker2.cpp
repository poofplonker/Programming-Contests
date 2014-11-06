//
//  cryptkicker2.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 21/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    int cases;
    cin >> cases;
    getchar();
    string dummy;
    getline(cin, dummy);
    for (int c = 0; c < cases; c++) {
        bool foxNotFound = true;
        int ilCounter = 0; //counts input line
        int alphaCounter = 0;
        int foxLine = 0;
        string input[110];
        int alphaBucket[30];
        getline(cin, input[ilCounter]);
        
        char charMap[30];
        char spaceChar = ' ';
        while (input[ilCounter] != "") {
            alphaCounter = 0;
            
        
            string target = "the quick brown fox jumps over the lazy dog";
            string curLine = input[ilCounter];
            //cout << curLine <<
            //cout << "os: " << curLine[17] << curLine[12] << curLine[26] << curLine[41] << endl;
            //cout << "size: " << curLine.size() << endl;
            if(curLine.size() == target.size() && curLine[17] == curLine[12] && curLine[12] == curLine[26] && curLine[12] == curLine[41]  && foxNotFound){
                for (int i = 0; i < 30; i++) {
                    alphaBucket[i] = 0;
                }
                for (int i = 0; i < input[ilCounter].size(); i++) {
                    if (alphaBucket[input[ilCounter][i] - 'a'] == 0) {
                        alphaCounter++;
                        alphaBucket[curLine[i] - 'a'] = 1;
                    }
                }
                //cout << "alphaCounter: " << alphaCounter << endl;
                //cout << curLine[0] << curLine[31] << curLine[1] << curLine[32] << curLine[2] << curLine[33] << endl;
                if(alphaCounter == 26 && curLine[0] == curLine[31] && curLine[1] == curLine[32] && curLine[2] == curLine[33]){
                    foxLine = ilCounter;
                    foxNotFound = false;
                    for (int i = 0; i < 26; i++) {
                        //cout << char(i + 'a') << " is at: " << target.find(i+'a') << " in "<< target << endl;
                        //cout << "That corresponds to " << curLine[target.find(i + 'a')] << " in the currentLine " << endl;
                        charMap[curLine[target.find(i + 'a')]-'a'] = char(i + 'a');
                       //cout << curLine[target.find(i+'a')] << " encodes: " << charMap[curLine[target.find(i+'a')]-'a'] << endl;
                    }
                    charMap[curLine[target.find(' ')]-'a'] = ' ';
                    spaceChar = target[curLine.find(' ')];
                }
            }
            ilCounter++;
            getline(cin,input[ilCounter]);
            //cout << input[ilCounter] << endl;
        }
        if(c != 0){
            cout << endl;
        }
        if(!foxNotFound){
            for (int i = 0; i < ilCounter; i++) {
                for (int j = 0; j < input[i].size(); j++){
                    if(input[i][j] == ' '){
                        cout << spaceChar;
                    }else{
                        cout << charMap[input[i][j]-'a'];
                    }
                }
                cout << endl;
            }
        }else{
            cout << "No solution." << endl;
        }
    }
}
