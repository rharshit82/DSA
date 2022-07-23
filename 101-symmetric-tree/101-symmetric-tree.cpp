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
        if(!root) return true;
        return isEqual(root->left, root->right);
    }
    bool isEqual(TreeNode* left, TreeNode* right){
        if(!left or !right) return (left==right);
        if(left->val!=right->val) return false;
        return isEqual(left->left,right->right) and isEqual(left->right, right->left);
    }
};