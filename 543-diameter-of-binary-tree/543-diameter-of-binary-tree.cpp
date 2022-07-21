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
    int findRes(TreeNode* root, int &d){
        if(!root) return 0;
        int left = findRes(root->left,d);
        int right = findRes(root->right,d);
        d = max(d, left+right);
        return 1 + max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int d =0;
        findRes(root,d);
        return d;
    }
};