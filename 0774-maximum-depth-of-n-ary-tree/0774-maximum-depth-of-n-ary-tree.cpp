/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
    if (!root) {
        return 0; // Base case: If the tree is empty, depth is 0.
    }

    int maxChildDepth = 0;

    // Recursively find the depth of each child.
    for (Node* child : root->children) {
        maxChildDepth = max(maxChildDepth, maxDepth(child));
    }

    // Add 1 for the current node's depth.
    return 1 + maxChildDepth;
}
};