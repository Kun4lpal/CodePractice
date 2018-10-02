class Solution {
private:
    void toBST(vector<int>& nums, int a, int b, TreeNode* root) {
        int mid = (a + b) >> 1;
        root->val = nums[mid];
        if (mid - 1 >= a) {
            root->left = new TreeNode(0);
            toBST(nums, a, mid - 1, root->left);
        }
        if (mid + 1 <= b) {
            root->right = new TreeNode(0);
            toBST(nums, mid + 1, b, root->right);
        }
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()) return NULL;
        TreeNode* root = new TreeNode(0);
        toBST(nums, 0, nums.size() - 1, root);
        return root;
    }
};