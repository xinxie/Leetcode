class RedBlackTree {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        bool color;
        TreeNode(int v, bool c): val(v), color(c) {}         
    }
public:
    void add(int value) {
        insert(root, value);
    }

private:
    static const bool RED = true;
    static const bool BLACK = false;
    TreeNode* root;

    void insert(TreeNode*& root, int value) {
        if(!root) root = new TreeNode(val, RED);
        else if(root->val < value) insert(root->right, value);
        else if(root->val > value) insert(root->left, value);

        // lean left
        if (isRed(root->right) && !isRed(root->left)) root = rotateLeft(root);

        // balance 4-node
        if(isRed(root->left) && isRed(root->left->left)) root = rotateRight(root);

        // split 4-node
        if(isRed(root->left) && isRed(root->right)) flipColors(root);

        return root;
    }


    bool isRed(TreeNode* root) {
        if(!root) return false;
        else return root->color == RED;
    }

    TreeNode* rotateLeft(TreeNode*& root) {
        assert isRed(root->right);
        TreeNode* tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        root->color = tmp->color;
        root->color = RED;
        return tmp;
    }

    TreeNode* rotateRight(TreeNode*& root) {
        assert isRed(root->left);
        TreeNode* tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        tmp->color = root->color;
        root->color = RED;
        return tmp;
    }

    void flipColors(TreeNode* root) {
        assert !isRed(root)
        assert isRed(root->left);
        assert isRed(root->right);
        root->color = RED;
        root->left.color = BLACK;
        root->right.color = BLACK;
    }

}
