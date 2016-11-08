#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval():start(0), end(0) {};
    Interval(int s, int e): start(s), end(e) {};
};

struct TreeNode {
    int max;
    TreeNode* left;
    TreeNode* right;
    Interval interval;
    TreeNode(Interval newInterval): interval(newInterval), left(NULL), right(NULL),max(newInterval.end) {}
};

TreeNode* root = NULL;

bool intersect(Interval i, Interval j) {
    if(i.start <= j.end && j.start <= i.end) return true;
    else return false;
}



// Searching binary search tree to find a overlapped interval.
TreeNode* findIntervals (Interval interval){
    TreeNode* curr = root;
    while(curr) {
        if(intersect(curr->interval, interval)) return curr;
        else if(!curr->left) curr = curr->right;
        else if(curr->left->max < interval.start ) curr = curr->right;
        else curr = curr->left;
    }
    return NULL;
}



// Notice: pass the root value by reference
void insert(TreeNode*& root, Interval newInterval) {
    if(root == NULL) {
        root = new TreeNode(newInterval);
    } else if(root->interval.start < newInterval.start) {
        insert(root->right, newInterval);
    } else {
        insert(root->left, newInterval);
    }

    // updating max value if possible.
    if(root->max < newInterval.end) {
        root->max = newInterval.end;
    }
}

void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << "[" << root->interval.start <<", " << root->interval.end << "] " << "max = " << root->max << endl;
    inorder(root->right);
}



int main() {
    vector<Interval> intervals = {{15,20}, {10,30}, {17,19}, {5,20}, {12,15}, {30,40}};
    for(int i = 0; i < intervals.size(); ++i) {
        insert(root, intervals[i]);
    }

    inorder(root);
    Interval x = {6, 7};
    auto find = findIntervals(x);
    if(!find) {
        cout << "No overlapping Intervals" << endl;
    } else {
        cout << "Overlapps with [" << find->interval.start << ", " << find->interval.end  << "]" << endl;
    }
}
