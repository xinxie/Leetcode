//
//  UnionFind.hpp
//  Leetcode
//
//  Created by Xin Xie on 10/11/16.
//  Copyright © 2016 Xin Xie. All rights reserved.
//

#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <stdio.h>
#include <vector>

using namespace std;


class quickUnion {
    
private:
    vector<int> root;
    vector<int> sz;
    
    void initialize();
    int getRoot(int i);

public:
    quickUnion(int size);
    
    bool connected(int p, int q);
    
    void Union(int p, int q);
    
};

#endif /* UnionFind_hpp */
