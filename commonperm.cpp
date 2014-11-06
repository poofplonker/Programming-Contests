//
//  commonperm.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 15/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
int main(void){
    string a, b;
    while (getline(cin, a) && getline(cin,b)) {
        //cout << "a: " << a << " and b: "<< b << endl;
        int aBucket[26], bBucket[26];
        for (int i = 0; i < 26; i++) {
            aBucket[i] = bBucket[i]= 0;
        }
        for (int i = 0; i < a.size(); i++) {
            aBucket[a[i]- 'a']++;
        }
        for (int i = 0; i < b.size(); i++) {
            bBucket[b[i]- 'a']++;
        }
        int numCommon = 0;
        for (int i = 0; i < 26; i++) {
            if (aBucket[i] > bBucket[i]) {
                numCommon = bBucket[i];
            }else{
                numCommon = aBucket[i];
            }
            for (int j = 0; j < numCommon; j++) {
                cout << char(i+'a');
            }
        }
        cout << endl;
    }
}