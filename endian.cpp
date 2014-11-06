//
//  endian.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 5/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <bitset>

using namespace std;

int main(void){
    int input;
    while(cin >> input){
        int output = 0;
        for (int i = 0; i < 4; i++) {
            int byte = (input >> (24-(8*i))&0xff);
            output += (byte << (8*i));
        }
        cout << input << " converts to "<< output << endl;
    }
}
