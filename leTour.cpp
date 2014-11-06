//
//  leTour.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 22/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
int main(void){
    int frontCount, rearCount,frontRing[12],rearRing[12];
    double driveRatios[120];
    
    cin >> frontCount;
    while (frontCount != 0) {
        cin >> rearCount;
        for (int i = 0; i < frontCount; i++) {
            cin >> frontRing[i];
        }
        for (int i = 0; i < rearCount; i++) {
            cin >> rearRing[i];
        }
        for (int i = 0; i < frontCount; i++) {
            for (int j = 0; j < rearCount; j++) {
                driveRatios[rearCount*i+j] = ((double)rearRing[j])/frontRing[i];
            }
        }
        double maxRatio = 0;
        double tempRatio;
        sort(driveRatios, driveRatios+(frontCount*rearCount));
        for (int i = 0; i < frontCount*rearCount-1; i++) {
            tempRatio = driveRatios[i+1]/driveRatios[i];
            if(tempRatio > maxRatio){
                maxRatio = tempRatio;
            }
        }
        cout << fixed << setprecision(2)<< maxRatio << endl;
        cin >> frontCount;
    }
}
