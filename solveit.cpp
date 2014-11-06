//
//  solveit.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 27/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#define epsilon 1e-09
#define epsilon2 1e-09
using namespace std;

double thatThing(double x, int p, int q, int r, int s, int t, int u){
    return p*exp(-1*x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x + u;
}
int main(void){
    int p,q,r,s,t,u;
    while (cin >> p >> q >> r >> s >> t >> u) {
        double x = 0.5;
        double oldX = 0;
        double low = 0;
        double high = 1;
        double result = thatThing(x, p , q, r, s ,t, u);
        //cout << result << " " << x << endl;
        if(thatThing(0, p, q, r, s, t, u)*thatThing(1, p, q, r, s, t, u) >0){
            cout << "No solution" << endl;
            continue;
        }
        while (abs(result) > epsilon2){
            if(result > 0){
                low= x;
            }else{
                high = x;
            }
            x = (high+low)/2;
            result = thatThing(x, p, q, r, s, t, u);
            //cout << result << " " << x << endl;
            oldX = x;
        }
        cout << fixed << setprecision(4) << x << endl;
    }
}
