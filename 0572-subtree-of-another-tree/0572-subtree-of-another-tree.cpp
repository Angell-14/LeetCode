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
   bool isIdentical(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
        return true; // Both trees are empty.
    }
    if (!root1 || !root2) {
        return false; // One tree is empty, and the other is not.
    }
    // Check if the current nodes match and recursively check their subtrees.
    return (root1->val == root2->val) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// Function to check if subRoot is a subtree of root.
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) {
        return false; // If the main tree is empty, subRoot cannot be a subtree.
    }
    if (isIdentical(root, subRoot)) {
        return true; // Found a match for subRoot in root.
    }
    // Recursively check the left and right subtrees.
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
};