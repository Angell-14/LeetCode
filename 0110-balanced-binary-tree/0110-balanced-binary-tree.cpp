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
    bool isBalanced(TreeNode* root) {
    return helper(root).first;
}

    pair<bool,int> helper(TreeNode* root){
          if(!root){
            return {true,0};
          }

          auto left = helper(root->left);
          auto right = helper(root->right);

          bool isBalanced = left.first && right.first && abs(left.second - right.second) <=1;

          int height = max(right.second , left.second) + 1;
          return {isBalanced, height};
    }
};