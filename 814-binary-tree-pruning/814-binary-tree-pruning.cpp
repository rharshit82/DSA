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
    bool prune(TreeNode* root){
        if(!root) return false;
        bool left = prune(root->left);
        bool right = prune(root->right);
        if(root->val==1 or left or right) {
            if(!left) root->left = NULL;
            if(!right) root->right = NULL;
            return true;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!prune(root)) return NULL;
        return root;
    }
};