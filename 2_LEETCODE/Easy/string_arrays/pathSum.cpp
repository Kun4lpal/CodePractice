class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> store;
        return helper(root, sum, store, 0);
    }
    int helper(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
        if (!root) return 0;
        root->val += pre;
        int res = (root->val == sum) + (store.count(root->val - sum) ? store[root->val - sum] : 0);
        store[root->val]++;
        res += helper(root->left, sum, store, root->val) + helper(root->right, sum, store, root->val);
        store[root->val]--;
        return res;
    }
};