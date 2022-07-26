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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res=0;
        queue<pair<TreeNode*,int>> q;
        if(!root) return res;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            unsigned long long mmin = q.front().second;
            unsigned long long left, right;
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front().first;
                unsigned long long val = q.front().second-mmin;
                if(i==0) left = val;
                if(i==sz-1) right = val;
                q.pop();
                if(curr->left) q.push({curr->left, 2*val+1});
                if(curr->right) q.push({curr->right, 2*val+2});
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};