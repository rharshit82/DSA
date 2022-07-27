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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(first->val,second->val);
    }
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        if(!first and root->val < prev->val){
            first = prev;
        }
        if(first and root->val < prev->val){
            second = root;
        }
        prev = root;
        traverse(root->right);
    }
};