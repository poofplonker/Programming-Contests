//
//  idCodes.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 5/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int main(void){
    string input;
    getline(cin, input);
    while (input != "#") {
        if(next_permutation(input.begin(), input.end())){
            cout << input << endl;
        }else{
            cout << "No Successor" << endl;
        }
        getline(cin,input);
    }
    

}
