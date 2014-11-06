//
//  ultrasort.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 5/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

long mergeSort(int begin, int end, int* array, int* extraArray){
    long counter = 0;
    int middle = (end+begin)/2;
    int x = begin;
    int y = middle;
    if(end-begin > 1){
        counter += mergeSort(begin, middle, array,extraArray);
        counter += mergeSort(middle, end,array,extraArray);
    }
//    cout << "Full array after merge: " << endl;
//    for (int j = begin; j < end; j++) {
//        cout << array[j] << " ";
//    }
//    cout << endl;
    int i = 0;
    while (x != middle && y != end+1) {
        if(x == middle){
            extraArray[i] = array[y++];
            //cout << "x at middle: adding " << extraArray[i] << endl;
        }else if(y == end){
            extraArray[i] = array[x++];
            //cout << "y at middle: end " << extraArray[i] << endl;
        }
        else if(array[y] < array[x]){
            counter += middle-x;
            extraArray[i] = array[y++];
            //cout << "Added " << middle-x << " to the counter for swapping " << extraArray[i] << " ahead of " << array[x] << endl;
        }else{
            extraArray[i] = array[x++];
            //cout << "normal ordering " << extraArray[i]  << " ahead of "<< array[y] <<  endl;
            //cout << "Middle : " << middle << " - x: " << x << endl;
        }
        i++;
    }
    for (int j = 0; j < i; j++) {
        array[begin+j] = extraArray[j];
    }
    return counter;
}

int main(void){
    int input;
    while (true) {
        cin >> input;
        if(!input){
            //cout << 0 << endl;
            return 0;
        }
        int unsorted[500500], extraArray[500500];
        for (int c = 0; c < input; c++) {
            cin >> unsorted[c];
        }
        long counter = mergeSort(0, input, unsorted, extraArray);
        cout << counter << endl;
    }
}
