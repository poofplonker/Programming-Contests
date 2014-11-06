//
//  3nplus1.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 27/06/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int bot,top;
    int index[1024];
    while (cin >> bot >> top){
        int max;
        int temptop = top;
        int tempbot = bot;
        if(bot > top){
            int temp = temptop;
            temptop = tempbot;
            tempbot = temp;
        }
        max = 0;
        for (int i = tempbot; i <= temptop; i++) {
            int counter = 1; //counter counts the cycle length
            long value = i;   //value is the start point of 3n+1
            //cout << value << " ";
            while (value != 1) {
                if (value%2) {  //if odd
                    value = 3*value +1;
                    value >>=1;
                    counter+=2;
                }else{
                    value >>=1;
                    counter++;
                }
                //cout << value << " ";
                
            }
            //cout << endl;
            if(counter > max){
                max = counter;
            }
        }
        cout << bot << " " << top << " " <<  max << endl;
    }
    return 0;
}
