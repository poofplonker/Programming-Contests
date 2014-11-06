//
//  stackemup.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 7/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <sstream>

using  namespace std;

void unrank(int i){
    int suit, value;
    string suitString, valueString;
    suit = i/13;
    value = i%13;
    switch (value) {
        case 12:
            valueString = "Ace";
            break;
        case 9:
            valueString = "Jack";
            break;
        case 10:
            valueString = "Queen";
            break;
        case 11:
            valueString = "King";
            break;
        default:
            stringstream ss;
            ss << (value+2);
            valueString = ss.str();
            break;
    }
    switch (suit) {
        case 0:
            suitString = "Clubs";
            break;
        case 1:
            suitString = "Diamonds";
            break;
        case 2:
            suitString = "Hearts";
            break;
        case 3:
            suitString = "Spades";
            break;
        default:
            break;
    }
    cout << valueString << " of " << suitString << endl;
    
}

int main(void){
    bool first = true;
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int decka[52],deckb[52], shuffles[100][52], num_shuffles, shuf;
        int* oldShuffle = decka;
        int* newShuffle = deckb;
        int* temp;
        for (int i = 0; i < 52; i++) {
            decka[i] = deckb[i] = i;
        }
        cin >> num_shuffles;
        //cout << "num_shuffles: " << num_shuffles<< endl;
        for (int s = 0; s < num_shuffles; s++) {
            //cout << "Shuffle: ";
            for (int i = 0; i < 52; i++) {
                cin >> shuffles[s][i];
                //cout << shuffles[s][i] << " ";
            }
            //cout << endl;
        }
        string input;
        getchar();
        getline(cin, input);
        
        while (input != "" ) {
            //cout << "Input: " << input << endl;
            shuf = stoi(input)-1;
            for (int i = 0; i < 52; i++) {
                newShuffle[i] = oldShuffle[shuffles[shuf][i]-1];
            }
            temp = oldShuffle;
            oldShuffle = newShuffle;
            newShuffle = temp;
            if (cin.eof()) {
                break;
            }
            getline(cin, input);
        }
        if (!first) {
            cout << endl;
        }
        first = false;
        for (int i = 0; i < 52; i++) {
            unrank(oldShuffle[i]);
            
        }

        
        
        
    }
}
