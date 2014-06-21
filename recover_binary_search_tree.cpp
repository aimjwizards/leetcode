    // traverse using the in-order
		// find the node whose next node is smaller than itself
		// remember to jump out of the recursion as soon as the node is found
		// using flag to notate this 
		void findLeft(TreeNode *root, int &lhs, TreeNode *&l_node, bool &flag) {
        if(root==nullptr || flag) return;
        findLeft(root->left, lhs, l_node, flag);
        if(flag) return;
        if(root->val<lhs) { flag = true; return; }
        else {  lhs = root->val; l_node = root;}
        findLeft(root->right, lhs, l_node, flag);
    }
		// traverse using the reverse in-order
		// find the node whose prev node is bigger than itself
		// remember to jump out of the recursion as soon as the node is found
		// using flag to notate this
    void findRight(TreeNode *root, int &rhs, TreeNode *&r_node, bool &flag) {
        if(root==nullptr || flag) return;
        findRight(root->right, rhs, r_node, flag);
        if(flag) return;
        if(root->val>rhs) { flag = true; return ;}
        else { rhs = root->val; r_node = root; }
        findRight(root->left, rhs, r_node, flag);
    }
    void recoverTree(TreeNode *root) {
        int lhs = INT_MIN; 
        TreeNode *l_node = nullptr;
        bool flag = false;
        findLeft(root, lhs, l_node, flag);
        int rhs = INT_MAX;
        TreeNode *r_node = nullptr;
        flag = false;
        findRight(root, rhs, r_node, flag);
        swap(l_node->val, r_node->val);
    }
