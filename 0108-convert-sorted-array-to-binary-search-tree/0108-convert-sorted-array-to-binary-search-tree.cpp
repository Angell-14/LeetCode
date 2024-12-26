/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()){
            return nullptr;
        }
        return helper(nums,0, nums.size() - 1);
    }

   TreeNode* helper(const vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr; // Base case: no elements to process
    }

    // Prevent unsigned overflow by ensuring indices are valid and using signed integers.
    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(nums[mid]);

    // Recursively construct the left and right subtrees.
    node->left = helper(nums, left, mid - 1);
    node->right = helper(nums, mid + 1, right);

    return node;
}
};