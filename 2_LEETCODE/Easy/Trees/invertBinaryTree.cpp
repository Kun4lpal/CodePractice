// here we are inverting at all levels
TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        if(root!=NULL){
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        }
        return root;
}