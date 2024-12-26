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
    void dfs(TreeNode* root, string currentPath, vector<string>& paths) {
    if (!root) {
        return; // Base case: if the node is null, return.
    }

    // Append the current node's value to the path.
    currentPath += to_string(root->val);

    // If it's a leaf node, add the path to the result.
    if (!root->left && !root->right) {
        paths.push_back(currentPath);
        return;
    }

    // If not a leaf, append "->" and recurse on left and right children.
    currentPath += "->";
    dfs(root->left, currentPath, paths);
    dfs(root->right, currentPath, paths);
}

// Main function to return all root-to-leaf paths.
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    dfs(root, "", paths); // Start DFS with an empty current path.
    return paths;
}
};