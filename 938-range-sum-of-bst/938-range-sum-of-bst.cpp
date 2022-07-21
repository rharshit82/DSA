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
    void rangeSum(TreeNode* root, int low, int high, int &res){
        if(!root) return;
        if(root->val>=low and root->val<=high){
            res+=root->val;
            rangeSum(root->left,low,high,res);
            rangeSum(root->right,low,high,res);
        } else if(root->val>=low){
            rangeSum(root->left,low,high,res);
        } else if(root->val<=high){
            rangeSum(root->right,low,high,res);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res=0;
        rangeSum(root,low,high,res);
        return res;
    }
};