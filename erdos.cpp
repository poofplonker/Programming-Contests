//
//  erdos.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 7/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
int main(void){
    int cases;
    //cout << "Starting." << endl;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int num_papers, num_peeps;
        
        cin >> num_papers >> num_peeps;
        getchar();
        set<string>* papers = new set<string>[num_papers];
        //cout << "Declared papers" << endl;
        unordered_map<string,int> people;
        string input;
        for (int p = 0; p < num_papers; p++) {
            getline(cin, input);
            //cout << "Processing: " << input << endl;
            int position = 0;
            int lastEnd = 0;
            while (!(input[position] == '.' && input[position+1] == ':')) {
                //cout << "Handling: " << input[position] << " "<<input[position+1] << endl;
                if (input[position] == '.' && input[position+1] == ',') {
                    papers[p].insert(input.substr(lastEnd, position-lastEnd+1));
                    //cout << "Inserting: " << input.substr(lastEnd, position - lastEnd+1)<< endl;
                    people[input.substr(lastEnd,position-lastEnd+1)] = -1;
                    lastEnd = position+3;
                    position ++;
                }
                position++;
            }
            papers[p].insert(input.substr(lastEnd, position-lastEnd+1));
            //cout << "Inserting: " << input.substr(lastEnd, position - lastEnd+1)<< endl;
            people[input.substr(lastEnd,position-lastEnd+1)] = -1;
        }
        
        set<string> workingSet;
        set<string> updatedSet;
        string erdos = "Erdos, P.";
        workingSet.insert(erdos);
        int distance = 1;
        while (workingSet != updatedSet) {
            //cout << "In loop for iteration " << distance << endl;
            updatedSet.insert(erdos);
            set_union(workingSet.begin(), workingSet.end(), updatedSet.begin(), updatedSet.end(), inserter(workingSet, workingSet.begin()));
            /*cout << "Working Set: " << endl;
            for (set<string>::iterator it = workingSet.begin(); it != workingSet.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;*/
            for (int p = 0; p < num_papers; p++) {
                /*cout << "Paper " << p << ":" << endl;
                for (set<string>::iterator it = papers[p].begin(); it != papers[p].end(); it++) {
                    cout << *it << " ";
                }
                cout << endl;*/
                set<string> result_set;
                set_intersection(papers[p].begin(), papers[p].end(), workingSet.begin(), workingSet.end(),inserter(result_set,result_set.begin()));
                //cout << "Result size: " << result_set.size() << endl;
                if(result_set.size()){
                    for (set<string>::iterator it = papers[p].begin(); it != papers[p].end(); it++) {
                        if(people[*it] < 0){
                            //cout << "Updating distance of " << *it << " to " << distance << endl;
                            updatedSet.insert(*it);
                            people[*it] = distance;
                        }
                    }
                }
                
            }
            /*cout << "Updated Set Now: " << endl;
            for (set<string>::iterator it = updatedSet.begin(); it != updatedSet.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;*/
            distance++;

        }
        cout << "Scenario " << c+1 << endl;
        for (int h = 0; h < num_peeps; h++) {
            getline(cin, input);
            if (people[input] > 0) {
                cout << input << " "<<people[input] << endl;
            }else{
                cout << input << " infinity" << endl;
            }
        }
    }
}