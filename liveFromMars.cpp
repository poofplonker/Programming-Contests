//
//  liveFromMars.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 8/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <cctype>
#include <map>
#include <sstream>

using namespace std;

int uf_find(int dna, int* dict, map<string,int> charDict){
    if(dna < 4){
        return dna;
    }else{
        return dict[dna] == dna  ? dna : uf_find(dict[dna], dict, charDict);
    }
}

void uf_union(int dnaOne, int dnaTwo, int* dict, map<string,int> charDict){
    if (dnaOne < 4 || uf_find(dnaTwo, dict,charDict) > 3) {
        dict[uf_find(dnaTwo,dict,charDict)] = uf_find(dnaOne,dict,charDict);
        //cout << "Parent of " << dnaTwo << " is " << uf_find(dnaOne,dict)<<endl;
    }else{
        dict[uf_find(dnaOne,dict,charDict)] = uf_find(dnaTwo,dict,charDict);
        //cout << "Parent of " << dnaOne << " is " << uf_find(dnaTwo,dict)<<endl;
    }
}

int stringToInt(string value, map<string,int> charDict){
    int realOne;
    if (value == "A" || value == "B" || value == "C" || value == "D") {
        realOne = charDict[value];
    }else{
        stringstream o;
        o << value;
        o >> realOne;
        realOne += 3;
        //cout << "Value: " << value << " turned into " << realOne << endl;
    }
    return realOne;
}

int main(void){
    int length;
    bool first = true;
    int counter = 0;
    while (!cin.eof()){
        //cout << "Case: " << counter << endl;
        cin >> length;
        counter++;
        string dnaOne[250];
        string dnaTwo[250];
        int dict[550];
        map<string,int> charDict;
        charDict["A"] = 0;
        charDict["B"] = 1;
        charDict["C"] = 2;
        charDict["D"] = 3;
        map<int,string> reverse;
        reverse[0] = "A";
        reverse[1] = "B";
        reverse[2] = "C";
        reverse[3] = "D";
        
        for (int i = 0; i < 500; i++) {
            dict[i] = i ;
        
        }
        for (int i = 0; i < length; i++) {
            cin >> dnaOne[i];
            counter++;
        }
        for (int i = 0; i < length; i++) {
            cin >> dnaTwo[i];
            counter++;
        }
        
        bool possible = true;
        for (int i = 0; i < length; i++) {
            //if dnaOne and dnaTwo parents are both chars, then its impossible
            int realOne, realTwo;
            
            realOne = stringToInt(dnaOne[i], charDict);
            realTwo = stringToInt(dnaTwo[i], charDict);
            int oneParent = uf_find(realOne,dict,charDict);
            int twoParent = uf_find(realTwo,dict,charDict);
            if(realOne > 3 || realTwo > 3){
                if( 4 > oneParent && 4>twoParent){
                    if(oneParent != twoParent){
                        possible = false;
                        break;
                    }
                }else{
                    uf_union(realOne,realTwo,dict,charDict);
                }
            }else{
                if (dnaOne[i] != dnaTwo[i]) {
                    possible = false;
                    break;
                }
            }
        }
        if(!first){
            cout << endl;
            counter++;
            
        }
        first = false;
        if(possible){
            cout << "YES" << endl;
            for (int i = 4;  i < 500; i++) {
                //cout << dict[i] << endl;
                if (uf_find(dict[i],dict,charDict) < 4) {
                    cout << i-3 << " " << reverse[uf_find(dict[i], dict, charDict)] << endl;
                }
            }
        }else{
            cout << "NO" << endl;
        }
    }
}
