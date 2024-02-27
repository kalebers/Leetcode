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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }
    
    int calculateDiameter(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftHeight = calculateDiameter(root->left, diameter);
        int rightHeight = calculateDiameter(root->right, diameter);
        
        // Update diameter for the current node
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }
};
