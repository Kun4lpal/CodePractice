

void DFS(TreeNode* root, int level, vector<vector<int>> &res){
    if (root == NULL) return;
    if (level == res.size()){
        res.push_back(vector<int>()); // Create a new level
    }
    
    res[level].push_back(root->val); // Add the current value to its level
    DFS(root->left, level+1,res); // Go to the next level
    DFS(root->right,level+1,res);
}
   
vector<vector<int> > levelOrderBottom(TreeNode *root){
  DFS(root, 0,vector<vector<int>> res);
  return vector<vector<int> > (res.rbegin(), res.rend());
}


// BFS with keeping track of n items or parents
vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> result;
      if (root) {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
          vector<int> line;
          int n = q.size();
          for (int i = 0; i < n; ++ i) {
            TreeNode *tmp = q.front();
            q.pop();
            line.push_back(tmp->val);
            if (tmp->left) {
              q.push(tmp->left);
            }
            if (tmp->right) {
              q.push(tmp->right);
            }
          }
          result.push_back(line);
        }
      }
      reverse(result.begin(), result.end());
      return result;
}