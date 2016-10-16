//
//  UnionFind.cpp
//  Leetcode
//
//  Created by Xin Xie on 10/11/16.
//  Copyright © 2016 Xin Xie. All rights reserved.
//

#include "UnionFind.hpp"

quickUnion::quickUnion(int size) {
    root.resize(size);
    sz.resize(size);
    initialize();
}


void quickUnion::Union (int p , int q) {
    int i = getRoot(p), j = getRoot(q);
    
    if(sz[i] < sz[j]) {
        root[i] = j;
        sz[j] += sz[i];
    } else {
        root[j] = i;
        sz[i] += sz[j];
    }
}

bool quickUnion:: connected (int p, int q) {
    return getRoot(p) == getRoot(q);
}



// Helper fucntion

void quickUnion::initialize() {
    for(int i = 0; i < root.size(); ++i) {
        root[i] = i;
        sz[i] = 1;
    }
}

int quickUnion::getRoot(int i) {
    while(i != root[i]) i = root[i];
    return i;
}
