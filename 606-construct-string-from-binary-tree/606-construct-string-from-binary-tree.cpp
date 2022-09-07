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
    bool construct(TreeNode* root, string& res){
        if(!root) return false;
        if(root->val<0){
            res+='-';
            res+=to_string(abs(root->val));
        }
        else{
            res+=to_string(root->val);
        }
        if(root->left or root->right){
            res+='(';
            construct(root->left, res);
            res+=')';
        if(root->right){
            res+='(';
            construct(root->right, res);
            res+=')';
        }
        }
       
        return true;
    }
    string tree2str(TreeNode* root) {
        string res = "";
        construct(root,res);
        return res;
    }
};