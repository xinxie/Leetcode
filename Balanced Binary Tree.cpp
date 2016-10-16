/* O(N) solution. Bottom up solution
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

private:
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        int lh = getHeight(root->left);
        if(lh == -1) return -1;
        int rh = getHeight(root->right);
        if(rh == -1) return -1;
        if(abs(lh-rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
};
