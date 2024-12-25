
 
  /*struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };*/
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; // This will store the inorder traversal
        helper(root, result); // Helper function to perform recursive traversal
        return result; // Return the result
    }

private:
    void helper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return; // Base case: If the node is null, do nothing
        }
        helper(node->left, result);      // Visit left subtree
        result.push_back(node->val);    // Add current node's value to result
        helper(node->right, result);    // Visit right subtree
    }
};
