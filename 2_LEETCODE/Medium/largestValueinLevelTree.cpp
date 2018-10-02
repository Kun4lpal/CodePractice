vector<int> largestValues(TreeNode* root) {
        vector<int> val;
        if(root == NULL){
            return val;
        }
        largest(val,root,0);
        return val;
}
    
void largest(vector<int> &val, TreeNode* root, int h){
        if(root == NULL){
            return;
        }
        if(val.size()<h+1){
            val.push_back(root->val);
        }else if(val[h] < root->val){
            val[h] = root->val;
        }        
        largest(val,root->left,h+1);
        largest(val,root->right,h+1);
}