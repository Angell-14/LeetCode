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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        calculateSumAndTilt(root, tilt);
        return tilt;
    }

private:
    int calculateSumAndTilt(TreeNode* node, int& tilt) {
        if (!node) {
            return 0; // Base case: if the node is null, its sum is 0
        }

        // Recursively calculate the sum of left and right subtrees
        int leftSum = calculateSumAndTilt(node->left, tilt);
        int rightSum = calculateSumAndTilt(node->right, tilt);

        // Update the tilt for the current node
        tilt += abs(leftSum - rightSum);

        // Return the total sum of the current subtree
        return node->val + leftSum + rightSum;
    }
};
