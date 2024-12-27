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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Base cases
        if (!root1) return root2; // If root1 is null, use root2
        if (!root2) return root1; // If root2 is null, use root1

        // Create a new node for the merged tree
        TreeNode* root3 = new TreeNode(root1->val + root2->val);

        // Recursively merge the left and right subtrees
        root3->left = mergeTrees(root1->left, root2->left);
        root3->right = mergeTrees(root1->right, root2->right);

        return root3; // Return the merged tree root
    }
};
