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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if the root is null or the root's value matches the target value
        if (!root || root->val == val) {
            return root;
        }

        // If the target value is smaller than the root's value, search the left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }

        // If the target value is larger than the root's value, search the right subtree
        return searchBST(root->right, val);
    }
};
