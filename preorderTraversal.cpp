struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

    void helper(TreeNode *root, vector<int> &result) {
        if(root == nullptr) return;
        result.push_back(root->val);
        helper(root->left, result);
        helper(root->right, result);
        return;
    }
    
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
