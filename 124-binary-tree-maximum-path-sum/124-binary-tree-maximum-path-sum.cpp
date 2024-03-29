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
    int helper(TreeNode* root, int &res){
        if(!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        res = max(res, root->val + left+ right);
        int rval = root->val +max(left,right);
        return (rval>0) ? rval: 0;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res=INT_MIN;
        helper(root,res);
        return res;
    }
};