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
    vector<string> res;
    void helper(TreeNode* root, string s){
        string val=to_string(root->val);
        s+=val;
        if(!root->left and !root->right){
            res.push_back(s);
            return;
        } 
        if(root->left) helper(root->left,s);
        if(root->right) helper(root->right,s);
        return;
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        string s="";
        helper(root,s);
        int ans=0;
        for(auto i: res){
            ans+=stoi(i);
        }
        return ans;
    }
};