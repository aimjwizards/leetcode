  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

    void helper(TreeNode *root, vector<int> &result) {
        if(root==nullptr) return;
        helper(root->left, result);
        helper(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
