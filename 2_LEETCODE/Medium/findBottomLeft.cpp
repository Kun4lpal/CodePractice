int findBottomLeftValue(TreeNode* root) {
    assert(root);
    stack<NodeInfo> s;
    s.push({root, 0, 0});
    int max_level = -1;
    int result;
    while (!s.empty()) {
      auto info = s.top();
      s.pop();
      auto node = info.node;
      auto level = info.level;
      auto seq = info.seq;
      if (node->right) s.push({node->right, level+1, (seq<<1)+1});
      if (node->left) s.push({node->left, level+1, seq<<1});

      if (level > max_level) {
        max_level = level;
        result = node->val;
      }
    }
    return result;
}