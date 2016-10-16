// Using Level Order Traversal (BFS)
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int depth = 0;
        q.push(root);
        while(!q.empty()) {
            depth++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(!(curr->left) && !(curr->right)) return depth;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
};
