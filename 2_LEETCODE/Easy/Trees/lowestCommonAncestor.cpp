This is search in bst note that we are always making use of bst properties;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root )
           return root; 
        else if(root->left && p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left,p,q);
        else if (root->right && p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;            
}