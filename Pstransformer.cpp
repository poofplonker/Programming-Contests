//
//  Pstransformer.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 23/10/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void){
    double a;
    int b;
    int c;
    char waste;
    while (cin >> a >> waste >> b  >> waste >> c) {
        cout << a << "," << b <<",";
        if(c <=6 || c > 18){
            cout << '0' << endl;
        }else{
            cout << '1' << endl;
        }
    }

}
