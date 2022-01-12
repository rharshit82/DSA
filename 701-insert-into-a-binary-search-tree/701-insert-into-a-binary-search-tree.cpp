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
    void helper(TreeNode* root,int val){
        if(!root) return ;
        if(root->val>val){
            if(root->left){
                insertIntoBST(root->left,val);
            }
            else{
                TreeNode* curr= new TreeNode(val);
                root->left=curr;
            }
        }
        else{
            if(root->right){
                insertIntoBST(root->right,val);
            }
            else{
                TreeNode* curr= new TreeNode(val);
                root->right=curr;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        helper(root,val);
        return root;
    }
};