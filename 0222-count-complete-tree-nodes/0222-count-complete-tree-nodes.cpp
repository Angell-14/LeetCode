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
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }

        int leftHeight= countheight(root->left);
        int rightHeight = countheight(root->right);

        if (leftHeight == rightHeight) {
        // Left subtree is a perfect binary tree
        return (1 << leftHeight) + countNodes(root->right);
    } else {
        // Right subtree is a perfect binary tree
        return (1 << rightHeight) + countNodes(root->left);
    }
    }

    int countheight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
            
        }
        return height;
    }
};