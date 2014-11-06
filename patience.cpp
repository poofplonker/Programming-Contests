//
//  patience.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 5/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>

using namespace std;

struct pile{
    char cards[52][2];
    int top;
    int count;
};

bool match(char one[], char two[]){
    return (one[1] == two[1] || one[0] == two[0]);
}

void update(pile cardArray[]){
    int s = 0;
    while (s < 52) {
        bool matchin = false;
        //cout << "Checking in update " << cardArray[s-1].top() << " and " << cardArray[s].top() << endl;
        if(cardArray[s].top == -1){
            s++;
            continue;
        }
        int back = s;
        int count = 0;
        while (count < 3 && back >= 0) {
            back--;
            if(cardArray[back].top > -1){
                count++;
            }
        }
        if(back >= 0  && cardArray[back].top > -1 && match(cardArray[s].cards[cardArray[s].top], cardArray[back].cards[cardArray[back].top])){
            //cout << "Merging stacks " << cardArray[s-3].top() << " and " << cardArray[s].top() << endl;
            cardArray[back].top++;
            cardArray[back].cards[cardArray[back].top][0] = cardArray[s].cards[cardArray[s].top][0];
            cardArray[back].cards[cardArray[back].top][1] = cardArray[s].cards[cardArray[s].top][1];
            cardArray[s].top--;
            s = 0;
            matchin = true;
            continue;
        }
        back = s;
        count = 0;
        while (count < 1 && back >= 0) {
            back--;
            if(cardArray[back].top > -1){
                count++;
            }
        }
        if(back >= 0  && cardArray[back].top > -1 && match(cardArray[s].cards[cardArray[s].top], cardArray[back].cards[cardArray[back].top])){
            cardArray[back].top++;
            cardArray[back].cards[cardArray[back].top][0] = cardArray[s].cards[cardArray[s].top][0];
            cardArray[back].cards[cardArray[back].top][1] = cardArray[s].cards[cardArray[s].top][1];
            cardArray[s].top--;
            matchin = true;
            s = 0;
        }

        if(!matchin){
            s++;
        }
        //cout << s << endl;
    }
}

int main(void){
    char input[2];
    while (true) {
        pile cardArray[52];
        for (int i = 0; i < 52; i++) {
            scanf("%s",input);
            //cout << input << endl;
            //cout << "Input: " << input << endl;
            if(input[0] == '#'){
                return 0;
            }else{
                //cout << "No match available" << endl;
                cardArray[i].top = 0;
                cardArray[i].cards[0][0] = input[0];
                cardArray[i].cards[0][1] = input[1];
                
            }
            
            //cardArray = update(cardArray);
                //cout << "Stack Count: " << stackCount << endl;
            
            
        }
        update(cardArray);
        
        

        int counter = 0;
        for (int i = 0; i < 52; i++) {
            if(cardArray[i].top > -1){
                counter++;
            }
        }
        cout << counter << " pile";
        if(counter > 1){
            cout << "s";
        }
        cout << " remaining: ";
        bool first = true;
        for (int i = 0; i < 52; i++) {
            if(cardArray[i].top != -1){
                if(first){
                    cout << cardArray[i].top+1;
                    first = false;
                }else{
                    cout << " " << cardArray[i].top+1;
                }
            }
        }
        cout << endl;
//        for (int i = 0; i < 52; i++) {
//            if (cardArray[i].top > -1) {
//            
//                cout << cardArray[i].cards[cardArray[i].top][0] << cardArray[i].cards[cardArray[i].top][1]<<" ";
//            }
//        }
//        cout << endl;
    }
    
}
