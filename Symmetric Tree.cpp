/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Iteration: Level Order Traversal
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left),q2.push(root->right);
        TreeNode* lr, *rr;
        while(q1.size() && q2.size()) {
            lr = q1.front(), rr = q2.front();
            q1.pop(), q2.pop();
            if(!(lr || rr)) continue; // if both pointers is NULL
            if(!(lr && rr)) return false;
            if(lr->val != rr->val) return false;
            q1.push(lr->left);
            q1.push(lr->right);
            q2.push(rr->right);
            q2.push(rr->left);
        }
        return true;
    }
};

//Recursively
class Solution {
private:
    bool isSymmetricHelper(TreeNode* lr, TreeNode* rr) {
        if(!(lr||rr)) return true;
        if(!(lr && rr)) return false;
        return (lr->val == rr ->val && isSymmetricHelper(lr -> left, rr ->right) && isSymmetricHelper(lr -> right, rr ->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root,root);
    }
};
