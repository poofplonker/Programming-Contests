//
//  parentheses.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 6/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;
int main(void){
    int cases;
    
    cin >> cases;
    getchar();
    for (int c = 0;  c < cases; c++) {
        string input;
        getline(cin, input);
        stack<char> charStack;
        bool valid = true;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(') {
                charStack.push(input[i]);
            }else if(input[i] == ')'){
                if (charStack.empty()) {
                    valid = false;
                }else if(charStack.top() == '('){
                    charStack.pop();
                }else{
                    valid = false;
                }
            }else if(input[i] == '['){
                charStack.push(input[i]);
            }else{
                if (charStack.empty()) {
                    valid = false;
                }else if(charStack.top() == '['){
                    charStack.pop();
                }else{
                    valid = false;
                }
            }
        }
        if(!charStack.empty()){
            valid = false;
        }
        if(valid){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        
    }
}
