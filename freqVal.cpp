//
//  freqVal.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 12/08/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;
typedef vector<pair<int,int> > vii;
typedef pair<int, int> ii;

vii tree;

ii queryTree(int* array,int first, int last, int node, int leftRange, int rightRange){
    if(first > rightRange || last < leftRange){
        ii temp(200000,-1);
        return temp;
    }
    else if ((leftRange == rightRange) || (first == leftRange && last == rightRange)) {
        return tree[node];
    }
    else{
        ii left = queryTree(array,first, last, node*2, leftRange, (leftRange+rightRange)/2);
        ii right = queryTree(array,first, last, node*2+1, (leftRange+rightRange)/2 + 1, rightRange);
        //0cout << "For next two, first: " << first << " and last: " << last << endl;
        //cout << "Answer to subquery " << leftRange  <<" " << (leftRange+rightRange)/2 << " is " << left.second << " with value " << left.first <<endl;
        //cout << "Answer to subquery " << (leftRange+rightRange)/2 + 1  <<" " << rightRange << " is " << right.second << " with value " << right.first << endl;
        if (left.first == right.first) {
            pair<int, int> temp(left.first,left.second+ right.second);
            return temp;
        }else if(left.first == 200000){
            return right;
        }else if(right.first == 200000){
            return left;
        }else{
            int rightIdx;
            int leftIdx;
            if (left.first == array[(leftRange+rightRange)/2 +1]) {
                rightIdx = 2*node+1;
                leftIdx = 2*node;
                while (rightIdx < tree.size() && tree[rightIdx].first != tree[leftIdx].first) {
                    rightIdx = rightIdx*2;
                }
                ii temp;
                temp.first = left.first;
                if(rightIdx < tree.size()){
                    temp.second = tree[rightIdx].second + left.second;
                }else{
                    temp.second = left.second;
                }
                
            }if (right.first == array[(leftRange+rightRange)/2]) {
                rightIdx = 2*node+1;
                leftIdx = 2*node;
                while (leftIdx < tree.size() && right.first != tree[leftIdx].first) {
                    leftIdx = leftIdx*2+1;
                }
                ii temp;
                if(temp.second < tree[leftIdx].second + right.second){
                    temp.first = right.first;
                    if(leftIdx < tree.size()){
                        temp.second = tree[leftIdx].second + right.second;
                    }else{
                        temp.second = right.second;
                    }
                }
                return temp;
            }else{
                ii temp;
                if(left.second > right.second){
                    temp.first = left.first;
                    temp.second = left.second;
                }else{
                    temp.first = right.first;
                    temp.second = right.second;
                }
                return temp;
            }
        }
    }
}

void build_tree(int*array, int node, int first, int last){
    if (first == last) {
        pair<int, int> thing(array[first],1);
        tree[node] = thing;
    }else{
        int leftIdx, rightIdx;
        leftIdx = 2*node;
        rightIdx = leftIdx + 1;
        build_tree(array, leftIdx, first,(first+last)/2);
        build_tree(array, rightIdx, (first+last)/2+1, last);
        if (tree[leftIdx].first == tree[rightIdx].first) {
            pair<int, int> temp(tree[leftIdx].first,tree[leftIdx].second+tree[rightIdx].second);
            tree[node] = temp;
        }else{
            ii temp(0,0);
            if (tree[leftIdx].first == array[(first+last)/2 + 1]) {
                while (rightIdx < tree.size() && tree[rightIdx].first != tree[leftIdx].first) {
                    rightIdx = rightIdx*2;
                }
                
                temp.first = tree[leftIdx].first;
                if(rightIdx < tree.size()){
                    temp.second = tree[rightIdx].second + tree[leftIdx].second;
                }else{
                    temp.second = tree[leftIdx].second;
                }
                tree[node] = temp;
                
            }if (tree[rightIdx].first == array[(first+last)/2]) {
                leftIdx = 2*node;
                rightIdx = leftIdx + 1;
                //cout << "Right Index: " << rightIdx << " array Index: " << (first+last)/2 << " first: " << tree[rightIdx].first << " array value:" << array[(first+last)/2] << endl;
                while (leftIdx < tree.size() && tree[rightIdx].first != tree[leftIdx].first) {
                    leftIdx = leftIdx*2+1;
                }
                //cout << "After loop, left index points to :" << tree[leftIdx].first << " with " << tree[leftIdx].second <<" elements"<<endl;
                int expression = 0;
                if(leftIdx < tree.size()){
                    expression = tree[leftIdx].second + tree[rightIdx].second;
                }else{
                    expression = tree[rightIdx].second;
                }
                if(expression> temp.second){
                    temp.second = expression;
                    temp.first = tree[rightIdx].first;
                    tree[node] = temp;
                }

            }else{
                if(tree[leftIdx].second > tree[rightIdx].second){
                    temp.first = tree[leftIdx].first;
                    temp.second = tree[leftIdx].second;
                }else{
                    temp.first = tree[rightIdx].first;
                    temp.second = tree[rightIdx].second;
                }
                tree[node] = temp;
            }
        }
    }
}

int main(void){
    while (true) {
        int array[1000010];
        int n, q;
        cin >> n;
        if(n == 0){
            return 0;
        }
        cin >> q;
        for (int i = 0; i < n; i++) {
            cin >> array[i];
            //cout << array[i] << " ";
        }
        
        int length = 2*pow(2, floor(log(n)/log(2))+1)+3;
        //1cout << length << endl;
        tree.resize(length);
        build_tree(array, 1, 0, n-1);
        /*for (int i = 0; i < length; i++) {
            cout << "Node " << i << ": "<<tree[i].first << " " << tree[i].second << endl ;
        }*/
        for (int i = 0; i < q; i++) {
            int first, last;
            cin >> first >> last;
            ii temp = queryTree(array, first-1, last-1, 1, 0, n-1);
            cout << temp.second << endl;
        }
        
    }
}
