// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
// Assume a BST is defined as follows:
//     The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//     The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//     Both the left and right subtrees must also be binary search trees.


// We are doing an inorder traversal in a binary search tree which means at some point we are bound to find maxCount;
vector<int> findMode(TreeNode* root) {
        vector<int>res;
        TreeNode* pre= NULL;
        int gmax = INT_MIN;
        int cnt=0;
        helper(root,res,pre,cnt, gmax);
        return res;
    }

void helper(TreeNode* root,vector<int>& res, TreeNode*& pre,int& cnt,int& gmax){
        if(!root) return ;
        helper(root->left,res,pre,cnt,gmax);
        if(pre!= NULL){
            cnt = pre->val == root->val ?  cnt+1: 1;
        }else
            cnt++;
        if(cnt >= gmax ){
            if(cnt > gmax) res.clear();
            res.push_back(root->val);
            gmax = cnt;
        }
        pre = root;
        helper(root->right,res,pre,cnt,gmax);
}