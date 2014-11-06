//
//  pirates.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 19/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <sstream>
#include <cmath>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<char> vc;

// segment tree: how many 1s in the range queried:

void lazy_prop(vi& segment_tree, vc& update_tree,int firstRange, int lastRange, int left, int right, int node);
void invert_range(vi& segment_tree, vc& update_tree,int firstRange, int lastRange, int left, int right, int node);
void set_range(vi& segment_tree, vc& update_tree,int firstRange, int lastRange, int left, int right, int node);
void unset_range(vi& segment_tree, vc& update_tree,int firstRange, int lastRange, int left, int right, int node);

void build_tree(int* pirateArray, int first, int last, int node, vi& segment_tree){
    if(first == last){
        segment_tree[node] = pirateArray[first];
    }else{
        build_tree(pirateArray, first, (first+last)/2, 2*node, segment_tree);
        build_tree(pirateArray, (first+last)/2 +1, last, 2*node + 1, segment_tree);
        segment_tree[node] = segment_tree[2*node] + segment_tree[2*node+1];
    }
    return;
}

void lazy_prop(vi& segment_tree, vc& update_tree,int firstRange, int lastRange, int left, int right, int node){
    switch (update_tree[node]) {
        case 'I':
            invert_range(segment_tree, update_tree,left, right, left, right, node);
            segment_tree[node] = segment_tree[2*node] + segment_tree[2*node+1];
            break;
        case 'F':
            set_range(segment_tree, update_tree,left, right, left, right, node);
            segment_tree[node] = segment_tree[2*node] + segment_tree[2*node+1];
            break;
        case 'E':
            unset_range(segment_tree, update_tree,left, right, left, right, node);
            segment_tree[node] = segment_tree[2*node] + segment_tree[2*node+1];
            break;
        default:
            break;
    }
    update_tree[node] = 'N';
}
void invert_range(vi& segment_tree, vc& update_tree,int firstRange, int lastRange, int left, int right, int node){
    //cout << "Invert range query -- " << "Range of query: " << firstRange <<  " " << lastRange << endl;
    //cout << "Node range: " << left << " " << right << endl;
    lazy_prop(segment_tree, update_tree, firstRange, lastRange, left, right, node);
    if(left > lastRange || right < firstRange){
        return;
    }
    if(left == right){
        segment_tree[node] = 1- segment_tree[node];
        update_tree[node] = 'N';
        return;
    }

        
    if (firstRange >= left && right <= lastRange && update_tree[node] != 'I') {
        //cout << "In base case" << endl;
        segment_tree[node] = right-left+1 - segment_tree[node];
        update_tree[node] = 'I';
        return;
    }


    if(firstRange <= left){
        invert_range(segment_tree, update_tree,firstRange, lastRange, left, (left+right)/2, 2*node);
    }else{
        invert_range(segment_tree, update_tree, firstRange, (left+right)/2, left, (left+right)/2, 2*node);
    }
    
    if(right >= lastRange){
        invert_range(segment_tree, update_tree,firstRange, lastRange, (left+right)/2 +1, right, 2*node+1);
    }else{
        invert_range(segment_tree, update_tree,(left+right)/2+1, lastRange, (left+right)/2 +1, right, 2*node+1);
    }
    update_tree[node] = 'N';
    segment_tree[node] = segment_tree[2*node]+segment_tree[2*node+1];
    return;
}


void print_tree(vi& segment_tree){
    cout << endl;
    int power = 1;
    int base =1;
    for (int i = 1; i < segment_tree.size(); i++) {
        cout << segment_tree[i] << " ";
        for(int j = 0; j  <power; j++){
            base *= 2;
        }
        if(base == i+1){
            cout << endl;
            power++;
        }
        base = 1;
    }
}

void print_tree(vc& segment_tree){
    cout << endl;
    int power = 1;
    int base =1;
    for (int i = 1; i < segment_tree.size(); i++) {
        cout << segment_tree[i] << " ";
        for(int j = 0; j  <power; j++){
            base *= 2;
        }
        if(base == i+1){
            cout << endl;
            power++;
        }
        base = 1;
    }
}
void set_range(vi& segment_tree, vc& update_tree, int firstRange, int lastRange, int left, int right, int node){
    if(update_tree[node]!= 'F'){
        lazy_prop(segment_tree, update_tree, firstRange, lastRange, left, right, node);
    }
    if(left > lastRange || right < firstRange){
        return;
    }else if(left == right){
        segment_tree[node] = 1;
        update_tree[node] = 'N';
        return;
    }
    if (firstRange <= left && right >= lastRange && update_tree[node] != 'F') {
        segment_tree[node] = right-left+1;
        update_tree[node] = 'F';
        return;
    }

    if(firstRange <= left){
        set_range(segment_tree, update_tree,firstRange, lastRange, left, (left+right)/2, 2*node);
    }else{
        set_range(segment_tree, update_tree,firstRange, (left+right)/2, left, (left+right)/2, 2*node);
    }
    
    if(right >= lastRange){
        set_range(segment_tree,update_tree, firstRange, lastRange, (left+right)/2 +1, right, 2*node+1);
    }else{
        set_range(segment_tree, update_tree,(left+right)/2+1, lastRange, (left+right)/2 +1, right, 2*node+1);
    }
    update_tree[node] = 'N';
    segment_tree[node] = segment_tree[2*node]+segment_tree[2*node+1];
    return;
}

void unset_range(vi& segment_tree, vc& update_tree,int firstRange, int lastRange, int left, int right, int node){
    //cout << "Empty range query -- " << "Range of query: " << firstRange <<  " " << lastRange << endl;
    //cout << "Node range: " << left << " " << right << endl;
    lazy_prop(segment_tree, update_tree, firstRange, lastRange, left, right, node);
    if(left > lastRange || right < firstRange){
        return;
    }else if(left == right){
        segment_tree[node] = 0;
        update_tree[node] = 'N';
        return;
    }
    if (firstRange <= left && right <= lastRange && update_tree[node] != 'E') {
        segment_tree[node] = 0;
        update_tree[node] = 'E';
        return;
    }


    if(firstRange <= left){
        unset_range(segment_tree, update_tree,firstRange, lastRange, left, (left+right)/2, 2*node);
    }else{
        unset_range(segment_tree, update_tree,firstRange, (left+right)/2, left, (left+right)/2, 2*node);
    }
    
    if(right >= lastRange){
        unset_range(segment_tree, update_tree,firstRange, lastRange, (left+right)/2 +1, right, 2*node+1);
    }else{
        unset_range(segment_tree, update_tree,(left+right)/2+1, lastRange, (left+right)/2 +1, right, 2*node+1);
    }
    update_tree[node] = 'N';
    segment_tree[node] = segment_tree[2*node]+segment_tree[2*node+1];
    return;
}

int query_range(vi& segment_tree,vc& update_tree, int firstRange, int lastRange, int left, int right, int node){
    lazy_prop(segment_tree, update_tree, firstRange, lastRange, left,right,node);
    if(left > lastRange || right < firstRange){
        return 0;
    }


    if(left >= firstRange && right  <= lastRange){
        return segment_tree[node];
    }else{
        int left_query;
        int right_query;
        if(firstRange <= left){
            left_query = query_range(segment_tree, update_tree,firstRange, lastRange, left, (left+right)/2, 2*node);
        }else{
            left_query = query_range(segment_tree, update_tree,firstRange, (left+right)/2, left, (left+right)/2, 2*node);
        }
        
        if(right >= lastRange){
            right_query = query_range(segment_tree, update_tree,firstRange, lastRange, (left+right)/2 +1, right, 2*node+1);
        }else{
            right_query = query_range(segment_tree, update_tree,(left+right)/2+1, lastRange, (left+right)/2 +1, right, 2*node+1);
        }
        
        return left_query + right_query;
    }
}
int main(void){
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int piratebuilder,pirateArray[1025000];
        int index = 0;
        cin >> piratebuilder;
        for (int p = 0; p < piratebuilder; p++) {
            int repetitions;
            
            string pirate;
            cin >> repetitions; getchar();
            cin >> pirate;
            for (int i = 0; i < repetitions; i++) {
                for (int j = 0; j < pirate.length(); j++) {
                    stringstream io;
                    int temp;
                    io << pirate[j];
                    io >> temp;
                    pirateArray[index] = temp;
                    //cout << pirateArray[index] << " ";
                    index++;
                    
                }
                
            }
            //cout << endl;
        }
        vi segment_tree;
        vc update_tree;
        int size = pow(2,ceil(log(index)/log(2))+1);
        segment_tree.resize(size);
        update_tree.resize(size,'N');
        build_tree(pirateArray, 0, index-1,1,segment_tree);
        //print_tree(segment_tree);
        //cout << "Size of tree: " << size << endl;
        //cout << "Index max: " << index << endl;
        int queries, start, finish;
        char code;
        cin >> queries;
        cout << "Case " << (c+1) << ":"<< endl;
        int query_count = 0;
        int query_result;
        for (int q = 0; q < queries; q++) {
            cin >> code >> start >> finish;
            //cout <<"Query " << q << ": "<< code << " " << start << " " << finish << endl;
            switch (code) {
                case 'F':
                    set_range(segment_tree, update_tree,start, finish, 0, index-1, 1);
                    break;
                case 'E':
                    unset_range(segment_tree, update_tree,start, finish, 0, index-1, 1);
                    break;
                case 'I':
                    invert_range(segment_tree, update_tree,start, finish, 0, index-1, 1);
                    break;
                case 'S':
                    query_result = query_range(segment_tree, update_tree,start, finish, 0, index-1, 1);
                    cout << "Q" << ++query_count << ": " << query_result << endl;
                    break;
                default:
                    //cout << "Invalid case"<< endl;
                    break;
            }
            //print_tree(segment_tree);
            //print_tree(update_tree);
            //print_tree(segment_tree);
        }
        
    }
}
