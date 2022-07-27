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
    bool helper(TreeNode* root, pair<long long,long long> validNodes){
        if(!root) return true;
        long long mn = validNodes.first;
        long long mx = validNodes.second;
        if(root->val >= mx or root->val <=mn) return false;
        if(root->left and !helper(root->left, {mn, root->val})) return false;
        if(root->right and !helper(root->right, {root->val, mx})) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, {LONG_MIN, LONG_MAX});
    }
};