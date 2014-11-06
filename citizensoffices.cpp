//
//  citizensoffices.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 22/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
typedef long long ll;

int distance(int onePlace, int anotherPlace){
    int onePlaceX = onePlace/5;
    int anotherPlaceX = anotherPlace/5;
    int onePlaceY = onePlace%5;
    int anotherPlaceY = anotherPlace%5;
    return abs(onePlaceX-anotherPlaceX) + abs(anotherPlaceY - onePlaceY);
}

void officePlacement(int officesPlaced,int* populated_regions, int lastPlaced, int* best_offices, int* current_offices, ll *bestDistance, int* city, int pop_regions){
    if(officesPlaced == 5){
        ll distanceThis = 0;
        for (int j = 0; j < pop_regions; j++) {
            ll localityDistance = 10;
            for (int i = 0; i < 5; i++) {
                //cout << "Distance from " << current_offices[i] << " and " << *it << " is:" << distance(current_offices[i],*it) << endl;;
                if(distance(current_offices[i],populated_regions[j]) < localityDistance){
                    localityDistance = distance(current_offices[i],populated_regions[j]);
                }
            }
            localityDistance *= city[populated_regions[j]];
            distanceThis += localityDistance;
        }
        if(distanceThis < *bestDistance){
            *bestDistance = distanceThis;
            for (int i = 0; i < 5; i++) {
                best_offices[i] = current_offices[i];
            }
        }
    }else{
        int put_office = lastPlaced+1;
        while (put_office < 25) {
            current_offices[officesPlaced] = put_office;
            officePlacement(officesPlaced+1,populated_regions,put_office, best_offices,current_offices, bestDistance, city,pop_regions);
            put_office++;
        }
    }
}

int main(void){
    int cases;
    cin >> cases;
    int city[30];
    int populated_regions[30];
    for (int c = 0; c < cases; c++) {
        int pop_regions, x, y,pop;
        int best_offices[5];
        ll bestDistance = 1000000000;
        ll* bestDistancePoint;
        bestDistancePoint = &bestDistance;
        int current_offices[5];
        for (int i = 0; i < 5; i++) {
            best_offices[i] = i;
        }
        cin >> pop_regions;
        for (int p = 0; p < pop_regions ; p++) {
            cin >> x >> y >> pop;
            city[x*5+y] = pop;
            populated_regions[p] = x*5+y;
        }
        officePlacement(0,populated_regions,-1,best_offices, current_offices, bestDistancePoint, city,pop_regions);
        for (int i = 0; i < 4; i++) {
            cout << best_offices[i] << " ";
        }
        cout <<best_offices[4]<< endl;
    }
}
