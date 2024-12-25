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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true; // An empty tree is symmetric
        }
        return isMirror(root->left, root->right); // Compare left and right subtrees
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true; // Both subtrees are empty
        }
        if (t1 == nullptr || t2 == nullptr) {
            return false; // One subtree is empty, and the other is not
        }
        // Check current nodes' values and recursively check their children in a mirrored fashion
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }
};
