// Problem: Verify Preorder Serialization of a Binary Tree
// In degree and out degree
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream str(preorder);
        string item;
        vector<string> vec;
        while(getline(str, item, ',')) vec.push_back(item);
        int diff = 1;
        for(auto node : vec) {
            if(--diff < 0) return false;
            if(node != "#") diff+=2;
        }
        return diff == 0;
    }
};

// For Postorder Serialization of a Binary Tree, just reversing the traversal
// order of binary tree. Same as the above one.


// For Inorder Serialization of a Binary Tree, it's hard to determine.
// For example: "#,1,#,2,#", which can be interpreted as tree rooted with 1 or 2.
