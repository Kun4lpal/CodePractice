bool dfs(TreeNode* root, int sum) {
    if (!root->left && !root->right) {
      return sum == root->val;
    }
    if (root->left && dfs(root->left, sum-root->val)) return true;
    if (root->right && dfs(root->right, sum-root->val)) return true;
    return false;
  }
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) return false;
    return dfs(root, sum);
  }